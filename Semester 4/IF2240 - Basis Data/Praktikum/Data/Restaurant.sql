/*M!999999\- enable the sandbox mode */
-- MariaDB dump 10.19-11.8.2-MariaDB, for Win64
--
-- Host: localhost    Database: restaurant
-- ------------------------------------------------------
-- Server version 11.8.2-MariaDB

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*M!100616 SET @OLD_NOTE_VERBOSITY=@@NOTE_VERBOSITY, NOTE_VERBOSITY=0 */;

CREATE DATABASE IF NOT EXISTS restaurant;
USE restaurant;

--
-- Drop tables (urutan dari child ke parent)
--
DROP TABLE IF EXISTS order_item;
DROP TABLE IF EXISTS orders;
DROP TABLE IF EXISTS customer;
DROP TABLE IF EXISTS payment;
DROP TABLE IF EXISTS dining;
DROP TABLE IF EXISTS waiter;
DROP TABLE IF EXISTS chef;
DROP TABLE IF EXISTS menu_item;
DROP TABLE IF EXISTS manager;

--
-- Table structure: manager
--
CREATE TABLE manager (
  manager_id INT NOT NULL,
  manager_name VARCHAR(80) NOT NULL,
  PRIMARY KEY (manager_id)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Table structure: waiter
--
CREATE TABLE waiter (
  waiter_id INT NOT NULL,
  waiter_name VARCHAR(80) NOT NULL,
  manager_id INT NOT NULL,
  PRIMARY KEY (waiter_id),
  KEY idx_waiter_manager (manager_id),
  CONSTRAINT fk_waiter_manager
    FOREIGN KEY (manager_id) REFERENCES manager (manager_id)
    ON DELETE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Table structure: chef
--
CREATE TABLE chef (
  chef_id INT NOT NULL,
  chef_name VARCHAR(80) NOT NULL,
  chef_rating TINYINT NOT NULL,
  PRIMARY KEY (chef_id),
  CONSTRAINT chk_chef_rating CHECK (chef_rating BETWEEN 1 AND 5)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Table structure: menu_item
--
CREATE TABLE menu_item (
  menu_item_id INT NOT NULL,
  menu_item_name VARCHAR(100) NOT NULL,
  description VARCHAR(255) NOT NULL,
  calories INT NOT NULL,
  price DECIMAL(10,2) NOT NULL,
  rating TINYINT NOT NULL,
  season VARCHAR(20) NOT NULL DEFAULT 'All Season',
  PRIMARY KEY (menu_item_id),
  CONSTRAINT chk_menu_calories CHECK (calories > 0),
  CONSTRAINT chk_menu_price CHECK (price > 0),
  CONSTRAINT chk_menu_rating CHECK (rating BETWEEN 1 AND 5)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Table structure: dining (pengganti RestTable)
--
CREATE TABLE dining (
  dining_id INT NOT NULL,
  num_people INT NOT NULL,
  num_seats INT NOT NULL,
  waiter_id INT NOT NULL,
  PRIMARY KEY (dining_id),
  KEY idx_dining_waiter (waiter_id),
  CONSTRAINT fk_dining_waiter
    FOREIGN KEY (waiter_id) REFERENCES waiter (waiter_id)
    ON DELETE CASCADE,
  CONSTRAINT chk_dining_people CHECK (num_people > 0),
  CONSTRAINT chk_dining_seats CHECK (num_seats > 0),
  CONSTRAINT chk_dining_capacity CHECK (num_seats >= num_people)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Table structure: payment
--
CREATE TABLE payment (
  payment_id INT NOT NULL,
  payment_type VARCHAR(20) NOT NULL,
  total_price DECIMAL(10,2) NOT NULL,
  billing_details VARCHAR(150) NOT NULL,
  tip DECIMAL(10,2) NOT NULL,
  payment_time DATETIME NOT NULL,
  PRIMARY KEY (payment_id),
  CONSTRAINT chk_payment_type CHECK (payment_type IN ('Cash', 'Credit', 'Debit', 'E-Wallet')),
  CONSTRAINT chk_payment_total CHECK (total_price > 0),
  CONSTRAINT chk_payment_tip CHECK (tip >= 0)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Table structure: orders (pengganti OrderTable)
--
CREATE TABLE orders (
  order_id INT NOT NULL,
  customer_id INT NOT NULL,
  num_items INT NOT NULL,
  order_status VARCHAR(20) NOT NULL,
  total_price DECIMAL(10,2) NOT NULL,
  payment_id INT DEFAULT NULL,
  dining_id INT NOT NULL,
  chef_id INT NOT NULL,
  ordered_at DATETIME NOT NULL,
  PRIMARY KEY (order_id),
  KEY idx_orders_customer (customer_id),
  KEY idx_orders_payment (payment_id),
  KEY idx_orders_dining (dining_id),
  KEY idx_orders_chef (chef_id),
  CONSTRAINT fk_orders_payment
    FOREIGN KEY (payment_id) REFERENCES payment (payment_id)
    ON DELETE SET NULL,
  CONSTRAINT fk_orders_dining
    FOREIGN KEY (dining_id) REFERENCES dining (dining_id)
    ON DELETE CASCADE,
  CONSTRAINT fk_orders_chef
    FOREIGN KEY (chef_id) REFERENCES chef (chef_id)
    ON DELETE CASCADE,
  CONSTRAINT chk_orders_num_items CHECK (num_items > 0),
  CONSTRAINT chk_orders_status CHECK (order_status IN ('Order Entered', 'Prep', 'Ready to Serve', 'Served', 'Cancelled')),
  CONSTRAINT chk_orders_total CHECK (total_price > 0)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Table structure: customer
--
CREATE TABLE customer (
  customer_id INT NOT NULL,
  customer_name VARCHAR(80) NOT NULL,
  date_of_entry DATETIME NOT NULL,
  date_of_exit DATETIME NOT NULL,
  PRIMARY KEY (customer_id),
  CONSTRAINT chk_customer_time CHECK (date_of_exit > date_of_entry)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

ALTER TABLE orders
  ADD CONSTRAINT fk_orders_customer
  FOREIGN KEY (customer_id) REFERENCES customer (customer_id)
  ON DELETE CASCADE;

--
-- Table structure: order_item (tambahan agar item order lebih terstruktur)
--
CREATE TABLE order_item (
  order_id INT NOT NULL,
  menu_item_id INT NOT NULL,
  quantity INT NOT NULL,
  item_price DECIMAL(10,2) NOT NULL,
  PRIMARY KEY (order_id, menu_item_id),
  KEY idx_order_item_menu (menu_item_id),
  CONSTRAINT fk_order_item_order
    FOREIGN KEY (order_id) REFERENCES orders (order_id)
    ON DELETE CASCADE,
  CONSTRAINT fk_order_item_menu
    FOREIGN KEY (menu_item_id) REFERENCES menu_item (menu_item_id)
    ON DELETE CASCADE,
  CONSTRAINT chk_order_item_qty CHECK (quantity > 0),
  CONSTRAINT chk_order_item_price CHECK (item_price > 0)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Seed data manual (tanpa procedure / loop)
-- Besar data:
-- manager: 8
-- chef: 10
-- waiter: 14
-- menu_item: 24
-- dining: 24
-- customer: 100
-- payment: 100
-- orders: 100
-- order_item: 300
--
START TRANSACTION;

INSERT INTO manager (manager_id, manager_name) VALUES
(1, 'Qori Kurniawan'),
(2, 'Fitri Abdullah'),
(3, 'Bella Indah Salim'),
(4, 'Chandra Purnomo'),
(5, 'Nina Ginting'),
(6, 'Rinaldi Mahendra'),
(7, 'Yudi Gunakarya'),
(8, 'Kridanto Suryono');

INSERT INTO chef (chef_id, chef_name, chef_rating) VALUES
(1, 'Dian Palupi', 5),
(2, 'Arya Setiaji', 4),
(3, 'Nanik Suryani', 4),
(4, 'Budi Raharjo', 5),
(5, 'Widyawan Prasetyo', 5),
(6, 'Indra Bimantara', 4),
(7, 'Lidia Kusuma', 4),
(8, 'Ratna Permadi', 5),
(9, 'Fajar Akbari', 4),
(10, 'Maya Lestari', 4);

INSERT INTO waiter (waiter_id, waiter_name, manager_id) VALUES
(101, 'Arif Budiman', 1),
(102, 'Windi Safitri', 1),
(103, 'Dhanar Putra', 2),
(104, 'Caca Puspita', 2),
(105, 'Reihan Syahputra', 3),
(106, 'Mega Lestari', 3),
(107, 'Pradana Yoga', 4),
(108, 'Siska Anggraini', 4),
(109, 'Firman Hakim', 5),
(110, 'Niken Wulandari', 5),
(111, 'Rizky Aditya', 6),
(112, 'Tiara Nabila', 6),
(113, 'Surya Pratama', 7),
(114, 'Zahra Aprilia', 8);

INSERT INTO menu_item (menu_item_id, menu_item_name, description, calories, price, rating, season) VALUES
(1, 'Nasi Goreng Kampung', 'Nasi goreng dengan ayam suwir dan acar', 640, 28.00, 5, 'All Season'),
(2, 'Mie Ayam Jamur', 'Mie ayam topping jamur dan sawi', 590, 26.00, 4, 'All Season'),
(3, 'Soto Ayam Lamongan', 'Soto ayam kuah kuning dengan koya', 430, 24.00, 4, 'Rainy'),
(4, 'Ayam Bakar Madu', 'Ayam bakar bumbu madu dengan sambal', 680, 36.00, 5, 'All Season'),
(5, 'Iga Bakar Sambal Matah', 'Iga sapi bakar dan sambal matah', 840, 58.00, 5, 'All Season'),
(6, 'Sate Ayam', 'Sate ayam dengan bumbu kacang', 520, 32.00, 4, 'All Season'),
(7, 'Gado-Gado', 'Sayuran rebus dengan saus kacang', 370, 22.00, 4, 'All Season'),
(8, 'Kwetiau Seafood', 'Kwetiau goreng dengan udang dan cumi', 700, 38.00, 5, 'All Season'),
(9, 'Sop Buntut', 'Sup buntut sapi kuah bening', 760, 54.00, 5, 'Rainy'),
(10, 'Rendang Sapi', 'Rendang sapi padang klasik', 790, 48.00, 5, 'All Season'),
(11, 'Nasi Uduk Komplet', 'Nasi uduk dengan lauk lengkap', 620, 30.00, 4, 'All Season'),
(12, 'Pecel Lele', 'Lele goreng sambal dan lalapan', 500, 25.00, 4, 'All Season'),
(13, 'Cumi Saus Padang', 'Cumi tumis saus padang pedas', 560, 44.00, 4, 'All Season'),
(14, 'Udang Mentega', 'Udang goreng saus mentega', 610, 46.00, 5, 'All Season'),
(15, 'Capcay Kuah', 'Capcay kuah aneka sayuran', 360, 29.00, 4, 'Rainy'),
(16, 'Tahu Telur', 'Tahu telur dengan bumbu kacang', 340, 21.00, 4, 'All Season'),
(17, 'Es Teh Manis', 'Teh melati dingin', 120, 8.00, 4, 'Summer'),
(18, 'Jus Alpukat', 'Jus alpukat kental manis', 260, 18.00, 5, 'Summer'),
(19, 'Kopi Susu Gula Aren', 'Kopi susu dingin gula aren', 210, 20.00, 5, 'All Season'),
(20, 'Lemon Tea', 'Teh lemon segar', 140, 12.00, 4, 'Summer'),
(21, 'Pisang Goreng Keju', 'Pisang goreng topping keju', 330, 19.00, 4, 'All Season'),
(22, 'Puding Cokelat', 'Puding cokelat dingin', 220, 16.00, 4, 'All Season'),
(23, 'Cheese Cake Mini', 'Mini cheesecake lembut', 280, 24.00, 5, 'All Season'),
(24, 'Es Campur', 'Es campur dengan sirup dan susu', 250, 17.00, 5, 'Summer');

INSERT INTO dining (dining_id, num_people, num_seats, waiter_id) VALUES
(1, 2, 2, 101),
(2, 4, 4, 102),
(3, 3, 4, 103),
(4, 5, 6, 104),
(5, 2, 2, 105),
(6, 6, 8, 106),
(7, 4, 4, 107),
(8, 2, 2, 108),
(9, 7, 8, 109),
(10, 3, 4, 110),
(11, 2, 2, 111),
(12, 5, 6, 112),
(13, 4, 6, 113),
(14, 2, 4, 114),
(15, 6, 8, 101),
(16, 3, 4, 102),
(17, 4, 4, 103),
(18, 2, 2, 104),
(19, 5, 6, 105),
(20, 4, 6, 106),
(21, 2, 2, 107),
(22, 8, 10, 108),
(23, 3, 4, 109),
(24, 6, 8, 110);

INSERT INTO customer (customer_id, customer_name, date_of_entry, date_of_exit) VALUES
(1, 'Qori Kurniawan', '2026-03-01 11:55:00', '2026-03-01 13:20:00'),
(2, 'Fitri Abdullah', '2026-03-01 12:10:00', '2026-03-01 13:35:00'),
(3, 'Bella Indah Salim', '2026-03-01 12:25:00', '2026-03-01 13:50:00'),
(4, 'Chandra Purnomo', '2026-03-01 12:50:00', '2026-03-01 14:15:00'),
(5, 'Nina Ginting', '2026-03-01 17:50:00', '2026-03-01 19:30:00'),
(6, 'Raka Pratama', '2026-03-01 18:05:00', '2026-03-01 19:40:00'),
(7, 'Siti Nuraini', '2026-03-02 11:40:00', '2026-03-02 13:10:00'),
(8, 'Dimas Fadli', '2026-03-02 12:00:00', '2026-03-02 13:40:00'),
(9, 'Nabila Putri', '2026-03-02 12:20:00', '2026-03-02 14:05:00'),
(10, 'Reza Mahendra', '2026-03-02 18:55:00', '2026-03-02 20:35:00'),
(11, 'Galih Prakoso', '2026-03-02 19:20:00', '2026-03-02 20:50:00'),
(12, 'Tania Lestari', '2026-03-02 19:35:00', '2026-03-02 21:15:00'),
(13, 'Fajar Nugraha', '2026-03-03 11:25:00', '2026-03-03 13:00:00'),
(14, 'Intan Maharani', '2026-03-03 11:50:00', '2026-03-03 13:25:00'),
(15, 'Yogi Setiawan', '2026-03-03 12:15:00', '2026-03-03 13:50:00'),
(16, 'Wulan Kartika', '2026-03-03 18:00:00', '2026-03-03 19:40:00'),
(17, 'Amara Cendana', '2026-03-03 18:30:00', '2026-03-03 20:10:00'),
(18, 'Bagas Saputra', '2026-03-04 11:30:00', '2026-03-04 13:05:00'),
(19, 'Celine Azzahra', '2026-03-04 12:00:00', '2026-03-04 13:35:00'),
(20, 'Farhan Maulana', '2026-03-04 12:25:00', '2026-03-04 14:00:00'),
(21, 'Aulia Saputra', '2026-03-06 11:00:00', '2026-03-06 12:46:00'),
(22, 'Bayu Pramudita', '2026-03-06 11:19:00', '2026-03-06 13:06:00'),
(23, 'Citra Kusuma', '2026-03-06 11:38:00', '2026-03-06 13:26:00'),
(24, 'Dewi Ramadhani', '2026-03-06 11:57:00', '2026-03-06 13:46:00'),
(25, 'Eko Putri', '2026-03-06 12:16:00', '2026-03-06 14:06:00'),
(26, 'Farah Wijaya', '2026-03-06 12:35:00', '2026-03-06 14:26:00'),
(27, 'Gilang Mulyani', '2026-03-06 12:54:00', '2026-03-06 14:46:00'),
(28, 'Hana Siregar', '2026-03-06 13:13:00', '2026-03-06 15:06:00'),
(29, 'Ilham Wibowo', '2026-03-06 13:32:00', '2026-03-06 15:26:00'),
(30, 'Jihan Herlambang', '2026-03-06 13:51:00', '2026-03-06 15:46:00'),
(31, 'Kevin Permata', '2026-03-06 14:10:00', '2026-03-06 16:06:00'),
(32, 'Laras Anindita', '2026-03-06 14:29:00', '2026-03-06 16:26:00'),
(33, 'Miko Maheswari', '2026-03-06 14:48:00', '2026-03-06 16:46:00'),
(34, 'Nadia Hakim', '2026-03-06 15:07:00', '2026-03-06 17:06:00'),
(35, 'Omar Pratama', '2026-03-06 15:26:00', '2026-03-06 17:26:00'),
(36, 'Putri Kurniadi', '2026-03-06 15:45:00', '2026-03-06 17:46:00'),
(37, 'Randy Pangestu', '2026-03-06 16:04:00', '2026-03-06 18:06:00'),
(38, 'Salsa Rahmawati', '2026-03-06 16:23:00', '2026-03-06 18:26:00'),
(39, 'Taufik Nugroho', '2026-03-06 16:42:00', '2026-03-06 18:46:00'),
(40, 'Uli Nabila', '2026-03-06 17:01:00', '2026-03-06 18:26:00'),
(41, 'Vino Saputra', '2026-03-06 17:20:00', '2026-03-06 18:46:00'),
(42, 'Wira Pramudita', '2026-03-06 17:39:00', '2026-03-06 19:06:00'),
(43, 'Xena Kusuma', '2026-03-06 17:58:00', '2026-03-06 19:26:00'),
(44, 'Yoga Ramadhani', '2026-03-06 18:17:00', '2026-03-06 19:46:00'),
(45, 'Zakia Putri', '2026-03-06 18:36:00', '2026-03-06 20:06:00'),
(46, 'Aulia Wijaya', '2026-03-06 18:55:00', '2026-03-06 20:26:00'),
(47, 'Bayu Mulyani', '2026-03-06 19:14:00', '2026-03-06 20:46:00'),
(48, 'Citra Siregar', '2026-03-06 19:33:00', '2026-03-06 21:06:00'),
(49, 'Dewi Wibowo', '2026-03-06 19:52:00', '2026-03-06 21:26:00'),
(50, 'Eko Herlambang', '2026-03-06 20:11:00', '2026-03-06 21:46:00'),
(51, 'Farah Permata', '2026-03-06 20:30:00', '2026-03-06 22:06:00'),
(52, 'Gilang Anindita', '2026-03-06 20:49:00', '2026-03-06 22:26:00'),
(53, 'Hana Maheswari', '2026-03-06 21:08:00', '2026-03-06 22:46:00'),
(54, 'Ilham Hakim', '2026-03-06 21:27:00', '2026-03-06 23:06:00'),
(55, 'Jihan Pratama', '2026-03-06 21:46:00', '2026-03-06 23:26:00'),
(56, 'Kevin Kurniadi', '2026-03-06 22:05:00', '2026-03-06 23:46:00'),
(57, 'Laras Pangestu', '2026-03-06 22:24:00', '2026-03-07 00:06:00'),
(58, 'Miko Rahmawati', '2026-03-06 22:43:00', '2026-03-07 00:26:00'),
(59, 'Nadia Nugroho', '2026-03-06 23:02:00', '2026-03-07 00:46:00'),
(60, 'Omar Nabila', '2026-03-06 23:21:00', '2026-03-07 01:06:00'),
(61, 'Putri Saputra', '2026-03-06 23:40:00', '2026-03-07 01:26:00'),
(62, 'Randy Pramudita', '2026-03-06 23:59:00', '2026-03-07 01:46:00'),
(63, 'Salsa Kusuma', '2026-03-07 00:18:00', '2026-03-07 02:06:00'),
(64, 'Taufik Ramadhani', '2026-03-07 00:37:00', '2026-03-07 02:26:00'),
(65, 'Uli Putri', '2026-03-07 00:56:00', '2026-03-07 02:46:00'),
(66, 'Vino Wijaya', '2026-03-07 01:15:00', '2026-03-07 03:06:00'),
(67, 'Wira Mulyani', '2026-03-07 01:34:00', '2026-03-07 03:26:00'),
(68, 'Xena Siregar', '2026-03-07 01:53:00', '2026-03-07 03:46:00'),
(69, 'Yoga Wibowo', '2026-03-07 02:12:00', '2026-03-07 04:06:00'),
(70, 'Zakia Herlambang', '2026-03-07 02:31:00', '2026-03-07 04:26:00'),
(71, 'Aulia Permata', '2026-03-07 02:50:00', '2026-03-07 04:46:00'),
(72, 'Bayu Anindita', '2026-03-07 03:09:00', '2026-03-07 05:06:00'),
(73, 'Citra Maheswari', '2026-03-07 03:28:00', '2026-03-07 05:26:00'),
(74, 'Dewi Hakim', '2026-03-07 03:47:00', '2026-03-07 05:46:00'),
(75, 'Eko Pratama', '2026-03-07 04:06:00', '2026-03-07 06:06:00'),
(76, 'Farah Kurniadi', '2026-03-07 04:25:00', '2026-03-07 06:26:00'),
(77, 'Gilang Pangestu', '2026-03-07 04:44:00', '2026-03-07 06:46:00'),
(78, 'Hana Rahmawati', '2026-03-07 05:03:00', '2026-03-07 07:06:00'),
(79, 'Ilham Nugroho', '2026-03-07 05:22:00', '2026-03-07 07:26:00'),
(80, 'Jihan Nabila', '2026-03-07 05:41:00', '2026-03-07 07:06:00'),
(81, 'Kevin Saputra', '2026-03-07 06:00:00', '2026-03-07 07:26:00'),
(82, 'Laras Pramudita', '2026-03-07 06:19:00', '2026-03-07 07:46:00'),
(83, 'Miko Kusuma', '2026-03-07 06:38:00', '2026-03-07 08:06:00'),
(84, 'Nadia Ramadhani', '2026-03-07 06:57:00', '2026-03-07 08:26:00'),
(85, 'Omar Putri', '2026-03-07 07:16:00', '2026-03-07 08:46:00'),
(86, 'Putri Wijaya', '2026-03-07 07:35:00', '2026-03-07 09:06:00'),
(87, 'Randy Mulyani', '2026-03-07 07:54:00', '2026-03-07 09:26:00'),
(88, 'Salsa Siregar', '2026-03-07 08:13:00', '2026-03-07 09:46:00'),
(89, 'Taufik Wibowo', '2026-03-07 08:32:00', '2026-03-07 10:06:00'),
(90, 'Uli Herlambang', '2026-03-07 08:51:00', '2026-03-07 10:26:00'),
(91, 'Vino Permata', '2026-03-07 09:10:00', '2026-03-07 10:46:00'),
(92, 'Wira Anindita', '2026-03-07 09:29:00', '2026-03-07 11:06:00'),
(93, 'Xena Maheswari', '2026-03-07 09:48:00', '2026-03-07 11:26:00'),
(94, 'Yoga Hakim', '2026-03-07 10:07:00', '2026-03-07 11:46:00'),
(95, 'Zakia Pratama', '2026-03-07 10:26:00', '2026-03-07 12:06:00'),
(96, 'Aulia Kurniadi', '2026-03-07 10:45:00', '2026-03-07 12:26:00'),
(97, 'Bayu Pangestu', '2026-03-07 11:04:00', '2026-03-07 12:46:00'),
(98, 'Citra Rahmawati', '2026-03-07 11:23:00', '2026-03-07 13:06:00'),
(99, 'Dewi Nugroho', '2026-03-07 11:42:00', '2026-03-07 13:26:00'),
(100, 'Eko Nabila', '2026-03-07 12:01:00', '2026-03-07 13:46:00');

INSERT INTO payment (payment_id, payment_type, total_price, billing_details, tip, payment_time) VALUES
(1, 'Cash', 73.00, 'INV-202603-001', 7.00, '2026-03-01 13:20:00'),
(2, 'Credit', 88.00, 'INV-202603-002', 8.00, '2026-03-01 13:37:00'),
(3, 'Debit', 79.00, 'INV-202603-003', 7.00, '2026-03-01 13:58:00'),
(4, 'E-Wallet', 72.00, 'INV-202603-004', 6.00, '2026-03-01 14:26:00'),
(5, 'Cash', 92.00, 'INV-202603-005', 9.00, '2026-03-01 19:26:00'),
(6, 'Credit', 84.00, 'INV-202603-006', 8.00, '2026-03-01 19:52:00'),
(7, 'Debit', 75.00, 'INV-202603-007', 7.00, '2026-03-02 13:05:00'),
(8, 'E-Wallet', 74.00, 'INV-202603-008', 7.00, '2026-03-02 13:30:00'),
(9, 'Cash', 83.00, 'INV-202603-009', 8.00, '2026-03-02 14:02:00'),
(10, 'Credit', 62.00, 'INV-202603-010', 6.00, '2026-03-02 20:20:00'),
(11, 'Debit', 53.00, 'INV-202603-011', 5.00, '2026-03-02 20:42:00'),
(12, 'E-Wallet', 50.00, 'INV-202603-012', 5.00, '2026-03-02 21:10:00'),
(13, 'Cash', 62.00, 'INV-202603-013', 6.00, '2026-03-03 12:55:00'),
(14, 'Credit', 72.00, 'INV-202603-014', 7.00, '2026-03-03 13:21:00'),
(15, 'Debit', 50.00, 'INV-202603-015', 5.00, '2026-03-03 13:45:00'),
(16, 'E-Wallet', 50.00, 'INV-202603-016', 5.00, '2026-03-03 19:31:00'),
(17, 'Cash', 29.00, 'INV-202603-017', 4.00, '2026-03-03 20:03:00'),
(18, 'Credit', 51.00, 'INV-202603-018', 5.00, '2026-03-04 13:00:00'),
(19, 'Debit', 51.00, 'INV-202603-019', 5.00, '2026-03-04 13:27:00'),
(20, 'E-Wallet', 40.00, 'INV-202603-020', 4.00, '2026-03-04 13:52:00'),
(21, 'Cash', 61.00, 'INV-202603-021', 6.00, '2026-03-04 20:18:00'),
(22, 'Credit', 82.00, 'INV-202603-022', 8.00, '2026-03-05 13:10:00'),
(23, 'Debit', 62.00, 'INV-202603-023', 6.00, '2026-03-05 19:28:00'),
(24, 'E-Wallet', 44.00, 'INV-202603-024', 5.00, '2026-03-05 20:12:00'),
(25, 'Credit', 65.00, 'INV-202603-025', 8.00, '2026-03-06 13:00:00'),
(26, 'Debit', 67.00, 'INV-202603-026', 9.00, '2026-03-06 13:13:00'),
(27, 'E-Wallet', 69.00, 'INV-202603-027', 10.00, '2026-03-06 13:26:00'),
(28, 'Cash', 64.00, 'INV-202603-028', 4.00, '2026-03-06 13:39:00'),
(29, 'Credit', 66.00, 'INV-202603-029', 5.00, '2026-03-06 13:52:00'),
(30, 'Debit', 68.00, 'INV-202603-030', 6.00, '2026-03-06 14:05:00'),
(31, 'E-Wallet', 70.00, 'INV-202603-031', 7.00, '2026-03-06 14:18:00'),
(32, 'Cash', 72.00, 'INV-202603-032', 8.00, '2026-03-06 14:31:00'),
(33, 'Credit', 74.00, 'INV-202603-033', 9.00, '2026-03-06 14:44:00'),
(34, 'Debit', 76.00, 'INV-202603-034', 10.00, '2026-03-06 14:57:00'),
(35, 'E-Wallet', 71.00, 'INV-202603-035', 4.00, '2026-03-06 15:10:00'),
(36, 'Cash', 73.00, 'INV-202603-036', 5.00, '2026-03-06 15:23:00'),
(37, 'Credit', 75.00, 'INV-202603-037', 6.00, '2026-03-06 15:36:00'),
(38, 'Debit', 77.00, 'INV-202603-038', 7.00, '2026-03-06 15:49:00'),
(39, 'E-Wallet', 79.00, 'INV-202603-039', 8.00, '2026-03-06 16:02:00'),
(40, 'Cash', 81.00, 'INV-202603-040', 9.00, '2026-03-06 16:15:00'),
(41, 'Credit', 83.00, 'INV-202603-041', 10.00, '2026-03-06 16:28:00'),
(42, 'Debit', 78.00, 'INV-202603-042', 4.00, '2026-03-06 16:41:00'),
(43, 'E-Wallet', 80.00, 'INV-202603-043', 5.00, '2026-03-06 16:54:00'),
(44, 'Cash', 82.00, 'INV-202603-044', 6.00, '2026-03-06 17:07:00'),
(45, 'Credit', 84.00, 'INV-202603-045', 7.00, '2026-03-06 17:20:00'),
(46, 'Debit', 86.00, 'INV-202603-046', 8.00, '2026-03-06 17:33:00'),
(47, 'E-Wallet', 41.00, 'INV-202603-047', 9.00, '2026-03-06 17:46:00'),
(48, 'Cash', 43.00, 'INV-202603-048', 10.00, '2026-03-06 17:59:00'),
(49, 'Credit', 38.00, 'INV-202603-049', 4.00, '2026-03-06 18:12:00'),
(50, 'Debit', 40.00, 'INV-202603-050', 5.00, '2026-03-06 18:25:00'),
(51, 'E-Wallet', 42.00, 'INV-202603-051', 6.00, '2026-03-06 18:38:00'),
(52, 'Cash', 44.00, 'INV-202603-052', 7.00, '2026-03-06 18:51:00'),
(53, 'Credit', 46.00, 'INV-202603-053', 8.00, '2026-03-06 19:04:00'),
(54, 'Debit', 48.00, 'INV-202603-054', 9.00, '2026-03-06 19:17:00'),
(55, 'E-Wallet', 50.00, 'INV-202603-055', 10.00, '2026-03-06 19:30:00'),
(56, 'Cash', 45.00, 'INV-202603-056', 4.00, '2026-03-06 19:43:00'),
(57, 'Credit', 47.00, 'INV-202603-057', 5.00, '2026-03-06 19:56:00'),
(58, 'Debit', 49.00, 'INV-202603-058', 6.00, '2026-03-06 20:09:00'),
(59, 'E-Wallet', 51.00, 'INV-202603-059', 7.00, '2026-03-06 20:22:00'),
(60, 'Cash', 53.00, 'INV-202603-060', 8.00, '2026-03-06 20:35:00'),
(61, 'Credit', 55.00, 'INV-202603-061', 9.00, '2026-03-06 20:48:00'),
(62, 'Debit', 57.00, 'INV-202603-062', 10.00, '2026-03-06 21:01:00'),
(63, 'E-Wallet', 52.00, 'INV-202603-063', 4.00, '2026-03-06 21:14:00'),
(64, 'Cash', 54.00, 'INV-202603-064', 5.00, '2026-03-06 21:27:00'),
(65, 'Credit', 56.00, 'INV-202603-065', 6.00, '2026-03-06 21:40:00'),
(66, 'Debit', 58.00, 'INV-202603-066', 7.00, '2026-03-06 21:53:00'),
(67, 'E-Wallet', 60.00, 'INV-202603-067', 8.00, '2026-03-06 22:06:00'),
(68, 'Cash', 62.00, 'INV-202603-068', 9.00, '2026-03-06 22:19:00'),
(69, 'Credit', 64.00, 'INV-202603-069', 10.00, '2026-03-06 22:32:00'),
(70, 'Debit', 59.00, 'INV-202603-070', 4.00, '2026-03-06 22:45:00'),
(71, 'E-Wallet', 61.00, 'INV-202603-071', 5.00, '2026-03-06 22:58:00'),
(72, 'Cash', 63.00, 'INV-202603-072', 6.00, '2026-03-06 23:11:00'),
(73, 'Credit', 65.00, 'INV-202603-073', 7.00, '2026-03-06 23:24:00'),
(74, 'Debit', 67.00, 'INV-202603-074', 8.00, '2026-03-06 23:37:00'),
(75, 'E-Wallet', 69.00, 'INV-202603-075', 9.00, '2026-03-06 23:50:00'),
(76, 'Cash', 71.00, 'INV-202603-076', 10.00, '2026-03-07 00:03:00'),
(77, 'Credit', 66.00, 'INV-202603-077', 4.00, '2026-03-07 00:16:00'),
(78, 'Debit', 68.00, 'INV-202603-078', 5.00, '2026-03-07 00:29:00'),
(79, 'E-Wallet', 70.00, 'INV-202603-079', 6.00, '2026-03-07 00:42:00'),
(80, 'Cash', 72.00, 'INV-202603-080', 7.00, '2026-03-07 00:55:00'),
(81, 'Credit', 74.00, 'INV-202603-081', 8.00, '2026-03-07 01:08:00'),
(82, 'Debit', 76.00, 'INV-202603-082', 9.00, '2026-03-07 01:21:00'),
(83, 'E-Wallet', 78.00, 'INV-202603-083', 10.00, '2026-03-07 01:34:00'),
(84, 'Cash', 73.00, 'INV-202603-084', 4.00, '2026-03-07 01:47:00'),
(85, 'Credit', 75.00, 'INV-202603-085', 5.00, '2026-03-07 02:00:00'),
(86, 'Debit', 77.00, 'INV-202603-086', 6.00, '2026-03-07 02:13:00'),
(87, 'E-Wallet', 79.00, 'INV-202603-087', 7.00, '2026-03-07 02:26:00'),
(88, 'Cash', 81.00, 'INV-202603-088', 8.00, '2026-03-07 02:39:00'),
(89, 'Credit', 83.00, 'INV-202603-089', 9.00, '2026-03-07 02:52:00'),
(90, 'Debit', 85.00, 'INV-202603-090', 10.00, '2026-03-07 03:05:00'),
(91, 'E-Wallet', 80.00, 'INV-202603-091', 4.00, '2026-03-07 03:18:00'),
(92, 'Cash', 82.00, 'INV-202603-092', 5.00, '2026-03-07 03:31:00'),
(93, 'Credit', 84.00, 'INV-202603-093', 6.00, '2026-03-07 03:44:00'),
(94, 'Debit', 39.00, 'INV-202603-094', 7.00, '2026-03-07 03:57:00'),
(95, 'E-Wallet', 41.00, 'INV-202603-095', 8.00, '2026-03-07 04:10:00'),
(96, 'Cash', 43.00, 'INV-202603-096', 9.00, '2026-03-07 04:23:00'),
(97, 'Credit', 45.00, 'INV-202603-097', 10.00, '2026-03-07 04:36:00'),
(98, 'Debit', 40.00, 'INV-202603-098', 4.00, '2026-03-07 04:49:00'),
(99, 'E-Wallet', 42.00, 'INV-202603-099', 5.00, '2026-03-07 05:02:00'),
(100, 'Cash', 44.00, 'INV-202603-100', 6.00, '2026-03-07 05:15:00');

INSERT INTO orders (
  order_id,
  customer_id,
  num_items,
  order_status,
  total_price,
  payment_id,
  dining_id,
  chef_id,
  ordered_at
) VALUES
(1, 1, 2, 'Served', 66.00, 1, 1, 1, '2026-03-01 12:10:00'),
(2, 2, 2, 'Served', 80.00, 2, 2, 2, '2026-03-01 12:25:00'),
(3, 3, 2, 'Served', 72.00, 3, 3, 3, '2026-03-01 12:40:00'),
(4, 4, 2, 'Ready to Serve', 66.00, 4, 4, 4, '2026-03-01 13:05:00'),
(5, 5, 2, 'Prep', 83.00, 5, 5, 5, '2026-03-01 18:10:00'),
(6, 6, 2, 'Served', 76.00, 6, 6, 6, '2026-03-01 18:35:00'),
(7, 7, 2, 'Served', 68.00, 7, 7, 7, '2026-03-02 11:50:00'),
(8, 8, 2, 'Prep', 67.00, 8, 8, 8, '2026-03-02 12:20:00'),
(9, 9, 2, 'Ready to Serve', 75.00, 9, 9, 9, '2026-03-02 12:45:00'),
(10, 10, 2, 'Cancelled', 56.00, 10, 10, 10, '2026-03-02 19:10:00'),
(11, 11, 2, 'Served', 48.00, 11, 11, 1, '2026-03-02 19:35:00'),
(12, 12, 2, 'Served', 45.00, 12, 12, 2, '2026-03-02 20:00:00'),
(13, 13, 2, 'Prep', 56.00, 13, 13, 3, '2026-03-03 11:40:00'),
(14, 14, 2, 'Served', 65.00, 14, 14, 4, '2026-03-03 12:05:00'),
(15, 15, 2, 'Ready to Serve', 45.00, 15, 15, 5, '2026-03-03 12:30:00'),
(16, 16, 2, 'Served', 45.00, 16, 16, 6, '2026-03-03 18:20:00'),
(17, 17, 2, 'Served', 25.00, 17, 17, 7, '2026-03-03 18:55:00'),
(18, 18, 2, 'Prep', 46.00, 18, 18, 8, '2026-03-04 11:45:00'),
(19, 19, 2, 'Served', 46.00, 19, 19, 9, '2026-03-04 12:15:00'),
(20, 20, 2, 'Served', 36.00, 20, 20, 10, '2026-03-04 12:40:00'),
(21, 1, 2, 'Ready to Serve', 55.00, 21, 21, 1, '2026-03-04 19:05:00'),
(22, 2, 2, 'Prep', 74.00, 22, 22, 2, '2026-03-05 11:55:00'),
(23, 4, 2, 'Served', 56.00, 23, 23, 3, '2026-03-05 18:15:00'),
(24, 5, 2, 'Served', 39.00, 24, 24, 4, '2026-03-05 19:00:00'),
(25, 25, 2, 'Prep', 55.00, 25, 1, 5, '2026-03-06 12:05:00'),
(26, 26, 2, 'Ready to Serve', 56.00, 26, 2, 6, '2026-03-06 12:19:00'),
(27, 27, 2, 'Order Entered', 57.00, 27, 3, 7, '2026-03-06 12:33:00'),
(28, 28, 2, 'Served', 58.00, 28, 4, 8, '2026-03-06 12:47:00'),
(29, 29, 2, 'Prep', 59.00, 29, 5, 9, '2026-03-06 13:01:00'),
(30, 30, 2, 'Ready to Serve', 60.00, 30, 6, 10, '2026-03-06 13:15:00'),
(31, 31, 2, 'Order Entered', 61.00, 31, 7, 1, '2026-03-06 13:29:00'),
(32, 32, 2, 'Served', 62.00, 32, 8, 2, '2026-03-06 13:43:00'),
(33, 33, 2, 'Prep', 63.00, 33, 9, 3, '2026-03-06 13:57:00'),
(34, 34, 2, 'Ready to Serve', 64.00, 34, 10, 4, '2026-03-06 14:11:00'),
(35, 35, 2, 'Order Entered', 65.00, 35, 11, 5, '2026-03-06 14:25:00'),
(36, 36, 2, 'Served', 66.00, 36, 12, 6, '2026-03-06 14:39:00'),
(37, 37, 2, 'Prep', 67.00, 37, 13, 7, '2026-03-06 14:53:00'),
(38, 38, 2, 'Ready to Serve', 68.00, 38, 14, 8, '2026-03-06 15:07:00'),
(39, 39, 2, 'Order Entered', 69.00, 39, 15, 9, '2026-03-06 15:21:00'),
(40, 40, 2, 'Served', 70.00, 40, 16, 10, '2026-03-06 15:35:00'),
(41, 41, 2, 'Prep', 71.00, 41, 17, 1, '2026-03-06 15:49:00'),
(42, 42, 2, 'Ready to Serve', 72.00, 42, 18, 2, '2026-03-06 16:03:00'),
(43, 43, 2, 'Order Entered', 73.00, 43, 19, 3, '2026-03-06 16:17:00'),
(44, 44, 2, 'Served', 30.00, 44, 20, 4, '2026-03-06 16:31:00'),
(45, 45, 2, 'Prep', 31.00, 45, 21, 5, '2026-03-06 16:45:00'),
(46, 46, 2, 'Ready to Serve', 32.00, 46, 22, 6, '2026-03-06 16:59:00'),
(47, 47, 2, 'Order Entered', 33.00, 47, 23, 7, '2026-03-06 17:13:00'),
(48, 48, 2, 'Served', 34.00, 48, 24, 8, '2026-03-06 17:27:00'),
(49, 49, 2, 'Prep', 35.00, 49, 1, 9, '2026-03-06 17:41:00'),
(50, 50, 2, 'Ready to Serve', 36.00, 50, 2, 10, '2026-03-06 17:55:00'),
(51, 51, 2, 'Order Entered', 37.00, 51, 3, 1, '2026-03-06 18:09:00'),
(52, 52, 2, 'Served', 38.00, 52, 4, 2, '2026-03-06 18:23:00'),
(53, 53, 2, 'Prep', 39.00, 53, 5, 3, '2026-03-06 18:37:00'),
(54, 54, 2, 'Ready to Serve', 40.00, 54, 6, 4, '2026-03-06 18:51:00'),
(55, 55, 2, 'Order Entered', 41.00, 55, 7, 5, '2026-03-06 19:05:00'),
(56, 56, 2, 'Served', 42.00, 56, 8, 6, '2026-03-06 19:19:00'),
(57, 57, 2, 'Prep', 43.00, 57, 9, 7, '2026-03-06 19:33:00'),
(58, 58, 2, 'Ready to Serve', 44.00, 58, 10, 8, '2026-03-06 19:47:00'),
(59, 59, 2, 'Order Entered', 45.00, 59, 11, 9, '2026-03-06 20:01:00'),
(60, 60, 2, 'Served', 46.00, 60, 12, 10, '2026-03-06 20:15:00'),
(61, 61, 2, 'Prep', 47.00, 61, 13, 1, '2026-03-06 20:29:00'),
(62, 62, 2, 'Ready to Serve', 48.00, 62, 14, 2, '2026-03-06 20:43:00'),
(63, 63, 2, 'Order Entered', 49.00, 63, 15, 3, '2026-03-06 20:57:00'),
(64, 64, 2, 'Served', 50.00, 64, 16, 4, '2026-03-06 21:11:00'),
(65, 65, 2, 'Prep', 51.00, 65, 17, 5, '2026-03-06 21:25:00'),
(66, 66, 2, 'Ready to Serve', 52.00, 66, 18, 6, '2026-03-06 21:39:00'),
(67, 67, 2, 'Order Entered', 53.00, 67, 19, 7, '2026-03-06 21:53:00'),
(68, 68, 2, 'Served', 54.00, 68, 20, 8, '2026-03-06 22:07:00'),
(69, 69, 2, 'Prep', 55.00, 69, 21, 9, '2026-03-06 22:21:00'),
(70, 70, 2, 'Ready to Serve', 56.00, 70, 22, 10, '2026-03-06 22:35:00'),
(71, 71, 2, 'Order Entered', 57.00, 71, 23, 1, '2026-03-06 22:49:00'),
(72, 72, 2, 'Served', 58.00, 72, 24, 2, '2026-03-06 23:03:00'),
(73, 73, 2, 'Prep', 59.00, 73, 1, 3, '2026-03-06 23:17:00'),
(74, 74, 2, 'Ready to Serve', 60.00, 74, 2, 4, '2026-03-06 23:31:00'),
(75, 75, 2, 'Order Entered', 61.00, 75, 3, 5, '2026-03-06 23:45:00'),
(76, 76, 2, 'Served', 62.00, 76, 4, 6, '2026-03-06 23:59:00'),
(77, 77, 2, 'Prep', 63.00, 77, 5, 7, '2026-03-07 00:13:00'),
(78, 78, 2, 'Ready to Serve', 64.00, 78, 6, 8, '2026-03-07 00:27:00'),
(79, 79, 2, 'Order Entered', 65.00, 79, 7, 9, '2026-03-07 00:41:00'),
(80, 80, 2, 'Served', 66.00, 80, 8, 10, '2026-03-07 00:55:00'),
(81, 81, 2, 'Prep', 67.00, 81, 9, 1, '2026-03-07 01:09:00'),
(82, 82, 2, 'Ready to Serve', 68.00, 82, 10, 2, '2026-03-07 01:23:00'),
(83, 83, 2, 'Order Entered', 69.00, 83, 11, 3, '2026-03-07 01:37:00'),
(84, 84, 2, 'Served', 70.00, 84, 12, 4, '2026-03-07 01:51:00'),
(85, 85, 2, 'Prep', 71.00, 85, 13, 5, '2026-03-07 02:05:00'),
(86, 86, 2, 'Ready to Serve', 72.00, 86, 14, 6, '2026-03-07 02:19:00'),
(87, 87, 2, 'Order Entered', 73.00, 87, 15, 7, '2026-03-07 02:33:00'),
(88, 88, 2, 'Served', 30.00, 88, 16, 8, '2026-03-07 02:47:00'),
(89, 89, 2, 'Prep', 31.00, 89, 17, 9, '2026-03-07 03:01:00'),
(90, 90, 2, 'Ready to Serve', 32.00, 90, 18, 10, '2026-03-07 03:15:00'),
(91, 91, 2, 'Order Entered', 33.00, 91, 19, 1, '2026-03-07 03:29:00'),
(92, 92, 2, 'Served', 34.00, 92, 20, 2, '2026-03-07 03:43:00'),
(93, 93, 2, 'Prep', 35.00, 93, 21, 3, '2026-03-07 03:57:00'),
(94, 94, 2, 'Ready to Serve', 36.00, 94, 22, 4, '2026-03-07 04:11:00'),
(95, 95, 2, 'Order Entered', 37.00, 95, 23, 5, '2026-03-07 04:25:00'),
(96, 96, 2, 'Served', 38.00, 96, 24, 6, '2026-03-07 04:39:00'),
(97, 97, 2, 'Prep', 39.00, 97, 1, 7, '2026-03-07 04:53:00'),
(98, 98, 2, 'Ready to Serve', 40.00, 98, 2, 8, '2026-03-07 05:07:00'),
(99, 99, 2, 'Order Entered', 41.00, 99, 3, 9, '2026-03-07 05:21:00'),
(100, 100, 2, 'Served', 42.00, 100, 4, 10, '2026-03-07 05:35:00');

INSERT INTO order_item (order_id, menu_item_id, quantity, item_price) VALUES
(1, 3, 2, 24.00),
(2, 6, 3, 32.00),
(2, 11, 1, 30.00),
(2, 16, 2, 21.00),
(3, 9, 1, 54.00),
(3, 14, 2, 46.00),
(3, 19, 3, 20.00),
(3, 24, 1, 17.00),
(3, 5, 2, 58.00),
(4, 12, 2, 25.00),
(4, 17, 3, 8.00),
(5, 15, 3, 29.00),
(5, 20, 1, 12.00),
(5, 1, 2, 28.00),
(5, 6, 3, 32.00),
(6, 18, 1, 18.00),
(7, 21, 2, 19.00),
(7, 2, 3, 26.00),
(7, 7, 1, 22.00),
(8, 24, 3, 17.00),
(8, 5, 1, 58.00),
(8, 10, 2, 48.00),
(8, 15, 3, 29.00),
(8, 20, 1, 12.00),
(9, 3, 1, 24.00),
(9, 8, 2, 38.00),
(10, 6, 2, 32.00),
(10, 11, 3, 30.00),
(10, 16, 1, 21.00),
(10, 21, 2, 19.00),
(11, 9, 3, 54.00),
(12, 12, 1, 25.00),
(12, 17, 2, 8.00),
(12, 22, 3, 16.00),
(13, 15, 2, 29.00),
(13, 20, 3, 12.00),
(13, 1, 1, 28.00),
(13, 6, 2, 32.00),
(13, 11, 3, 30.00),
(14, 18, 3, 18.00),
(14, 23, 1, 24.00),
(15, 21, 1, 19.00),
(15, 2, 2, 26.00),
(15, 7, 3, 22.00),
(15, 12, 1, 25.00),
(16, 24, 2, 17.00),
(17, 3, 3, 24.00),
(17, 8, 1, 38.00),
(17, 13, 2, 44.00),
(18, 6, 1, 32.00),
(18, 11, 2, 30.00),
(18, 16, 3, 21.00),
(18, 21, 1, 19.00),
(18, 2, 2, 26.00),
(19, 9, 2, 54.00),
(19, 14, 3, 46.00),
(20, 12, 3, 25.00),
(20, 17, 1, 8.00),
(20, 22, 2, 16.00),
(20, 3, 3, 24.00),
(21, 15, 1, 29.00),
(22, 18, 2, 18.00),
(22, 23, 3, 24.00),
(22, 4, 1, 36.00),
(23, 21, 3, 19.00),
(23, 2, 1, 26.00),
(23, 7, 2, 22.00),
(23, 12, 3, 25.00),
(23, 17, 1, 8.00),
(24, 24, 1, 17.00),
(24, 5, 2, 58.00),
(25, 3, 2, 24.00),
(25, 8, 3, 38.00),
(25, 13, 1, 44.00),
(25, 18, 2, 18.00),
(26, 6, 3, 32.00),
(27, 9, 1, 54.00),
(27, 14, 2, 46.00),
(27, 19, 3, 20.00),
(28, 12, 2, 25.00),
(28, 17, 3, 8.00),
(28, 22, 1, 16.00),
(28, 3, 2, 24.00),
(28, 8, 3, 38.00),
(29, 15, 3, 29.00),
(29, 20, 1, 12.00),
(30, 18, 1, 18.00),
(30, 23, 2, 24.00),
(30, 4, 3, 36.00),
(30, 9, 1, 54.00),
(31, 21, 2, 19.00),
(32, 24, 3, 17.00),
(32, 5, 1, 58.00),
(32, 10, 2, 48.00),
(33, 3, 1, 24.00),
(33, 8, 2, 38.00),
(33, 13, 3, 44.00),
(33, 18, 1, 18.00),
(33, 23, 2, 24.00),
(34, 6, 2, 32.00),
(34, 11, 3, 30.00),
(35, 9, 3, 54.00),
(35, 14, 1, 46.00),
(35, 19, 2, 20.00),
(35, 24, 3, 17.00),
(36, 12, 1, 25.00),
(37, 15, 2, 29.00),
(37, 20, 3, 12.00),
(37, 1, 1, 28.00),
(38, 18, 3, 18.00),
(38, 23, 1, 24.00),
(38, 4, 2, 36.00),
(38, 9, 3, 54.00),
(38, 14, 1, 46.00),
(39, 21, 1, 19.00),
(39, 2, 2, 26.00),
(40, 24, 2, 17.00),
(40, 5, 3, 58.00),
(40, 10, 1, 48.00),
(40, 15, 2, 29.00),
(41, 3, 3, 24.00),
(42, 6, 1, 32.00),
(42, 11, 2, 30.00),
(42, 16, 3, 21.00),
(43, 9, 2, 54.00),
(43, 14, 3, 46.00),
(43, 19, 1, 20.00),
(43, 24, 2, 17.00),
(43, 5, 3, 58.00),
(44, 12, 3, 25.00),
(44, 17, 1, 8.00),
(45, 15, 1, 29.00),
(45, 20, 2, 12.00),
(45, 1, 3, 28.00),
(45, 6, 1, 32.00),
(46, 18, 2, 18.00),
(47, 21, 3, 19.00),
(47, 2, 1, 26.00),
(47, 7, 2, 22.00),
(48, 24, 1, 17.00),
(48, 5, 2, 58.00),
(48, 10, 3, 48.00),
(48, 15, 1, 29.00),
(48, 20, 2, 12.00),
(49, 3, 2, 24.00),
(49, 8, 3, 38.00),
(50, 6, 3, 32.00),
(50, 11, 1, 30.00),
(50, 16, 2, 21.00),
(50, 21, 3, 19.00),
(51, 9, 1, 54.00),
(52, 12, 2, 25.00),
(52, 17, 3, 8.00),
(52, 22, 1, 16.00),
(53, 15, 3, 29.00),
(53, 20, 1, 12.00),
(53, 1, 2, 28.00),
(53, 6, 3, 32.00),
(53, 11, 1, 30.00),
(54, 18, 1, 18.00),
(54, 23, 2, 24.00),
(55, 21, 2, 19.00),
(55, 2, 3, 26.00),
(55, 7, 1, 22.00),
(55, 12, 2, 25.00),
(56, 24, 3, 17.00),
(57, 3, 1, 24.00),
(57, 8, 2, 38.00),
(57, 13, 3, 44.00),
(58, 6, 2, 32.00),
(58, 11, 3, 30.00),
(58, 16, 1, 21.00),
(58, 21, 2, 19.00),
(58, 2, 3, 26.00),
(59, 9, 3, 54.00),
(59, 14, 1, 46.00),
(60, 12, 1, 25.00),
(60, 17, 2, 8.00),
(60, 22, 3, 16.00),
(60, 3, 1, 24.00),
(61, 15, 2, 29.00),
(62, 18, 3, 18.00),
(62, 23, 1, 24.00),
(62, 4, 2, 36.00),
(63, 21, 1, 19.00),
(63, 2, 2, 26.00),
(63, 7, 3, 22.00),
(63, 12, 1, 25.00),
(63, 17, 2, 8.00),
(64, 24, 2, 17.00),
(64, 5, 3, 58.00),
(65, 3, 3, 24.00),
(65, 8, 1, 38.00),
(65, 13, 2, 44.00),
(65, 18, 3, 18.00),
(66, 6, 1, 32.00),
(67, 9, 2, 54.00),
(67, 14, 3, 46.00),
(67, 19, 1, 20.00),
(68, 12, 3, 25.00),
(68, 17, 1, 8.00),
(68, 22, 2, 16.00),
(68, 3, 3, 24.00),
(68, 8, 1, 38.00),
(69, 15, 1, 29.00),
(69, 20, 2, 12.00),
(70, 18, 2, 18.00),
(70, 23, 3, 24.00),
(70, 4, 1, 36.00),
(70, 9, 2, 54.00),
(71, 21, 3, 19.00),
(72, 24, 1, 17.00),
(72, 5, 2, 58.00),
(72, 10, 3, 48.00),
(73, 3, 2, 24.00),
(73, 8, 3, 38.00),
(73, 13, 1, 44.00),
(73, 18, 2, 18.00),
(73, 23, 3, 24.00),
(74, 6, 3, 32.00),
(74, 11, 1, 30.00),
(75, 9, 1, 54.00),
(75, 14, 2, 46.00),
(75, 19, 3, 20.00),
(75, 24, 1, 17.00),
(76, 12, 2, 25.00),
(77, 15, 3, 29.00),
(77, 20, 1, 12.00),
(77, 1, 2, 28.00),
(78, 18, 1, 18.00),
(78, 23, 2, 24.00),
(78, 4, 3, 36.00),
(78, 9, 1, 54.00),
(78, 14, 2, 46.00),
(79, 21, 2, 19.00),
(79, 2, 3, 26.00),
(80, 24, 3, 17.00),
(80, 5, 1, 58.00),
(80, 10, 2, 48.00),
(80, 15, 3, 29.00),
(81, 3, 1, 24.00),
(82, 6, 2, 32.00),
(82, 11, 3, 30.00),
(82, 16, 1, 21.00),
(83, 9, 3, 54.00),
(83, 14, 1, 46.00),
(83, 19, 2, 20.00),
(83, 24, 3, 17.00),
(83, 5, 1, 58.00),
(84, 12, 1, 25.00),
(84, 17, 2, 8.00),
(85, 15, 2, 29.00),
(85, 20, 3, 12.00),
(85, 1, 1, 28.00),
(85, 6, 2, 32.00),
(86, 18, 3, 18.00),
(87, 21, 1, 19.00),
(87, 2, 2, 26.00),
(87, 7, 3, 22.00),
(88, 24, 2, 17.00),
(88, 5, 3, 58.00),
(88, 10, 1, 48.00),
(88, 15, 2, 29.00),
(88, 20, 3, 12.00),
(89, 3, 3, 24.00),
(89, 8, 1, 38.00),
(90, 6, 1, 32.00),
(90, 11, 2, 30.00),
(90, 16, 3, 21.00),
(90, 21, 1, 19.00),
(91, 9, 2, 54.00),
(92, 12, 3, 25.00),
(92, 17, 1, 8.00),
(92, 22, 2, 16.00),
(93, 15, 1, 29.00),
(93, 20, 2, 12.00),
(93, 1, 3, 28.00),
(93, 6, 1, 32.00),
(93, 11, 2, 30.00),
(94, 18, 2, 18.00),
(94, 23, 3, 24.00),
(95, 21, 3, 19.00),
(95, 2, 1, 26.00),
(95, 7, 2, 22.00),
(95, 12, 3, 25.00),
(96, 24, 1, 17.00),
(97, 3, 2, 24.00),
(97, 8, 3, 38.00),
(97, 13, 1, 44.00),
(98, 6, 3, 32.00),
(98, 11, 1, 30.00),
(98, 16, 2, 21.00),
(98, 21, 3, 19.00),
(98, 2, 1, 26.00),
(99, 9, 1, 54.00),
(99, 14, 2, 46.00),
(100, 12, 2, 25.00),
(100, 17, 3, 8.00),
(100, 22, 1, 16.00),
(100, 3, 2, 24.00)
;

-- Sinkronisasi data turunan setelah variasi order_item
UPDATE orders o
SET o.num_items = (
  SELECT COALESCE(SUM(oi.quantity), 0)
  FROM order_item oi
  WHERE oi.order_id = o.order_id
);

UPDATE orders o
SET o.total_price = (
  SELECT COALESCE(ROUND(SUM(oi.quantity * oi.item_price), 2), 0)
  FROM order_item oi
  WHERE oi.order_id = o.order_id
);

UPDATE payment p
JOIN orders o ON o.payment_id = p.payment_id
SET p.total_price = o.total_price;

COMMIT;

--
-- Cek jumlah baris per tabel
--
SELECT 'manager' AS table_name, COUNT(*) AS row_count FROM manager
UNION ALL
SELECT 'chef', COUNT(*) FROM chef
UNION ALL
SELECT 'waiter', COUNT(*) FROM waiter
UNION ALL
SELECT 'menu_item', COUNT(*) FROM menu_item
UNION ALL
SELECT 'dining', COUNT(*) FROM dining
UNION ALL
SELECT 'payment', COUNT(*) FROM payment
UNION ALL
SELECT 'orders', COUNT(*) FROM orders
UNION ALL
SELECT 'customer', COUNT(*) FROM customer
UNION ALL
SELECT 'order_item', COUNT(*) FROM order_item;

/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;
/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*M!100616 SET NOTE_VERBOSITY=@OLD_NOTE_VERBOSITY */;

