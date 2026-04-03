#ifndef GACHA_EXCEPTION_HPP
#define GACHA_EXCEPTION_HPP

#include <exception>
#include <string>

/**
 * @brief Base class untuk semua exception pada sistem Gacha ini.
 *
 * @note Custom Exception
 * Dalam C++, kita dapat membuat exception kustom dengan mewarisi (inherit)
 * kelas std::exception secara publik. Hal ini memungkinkan berbagai jenis
 * exception spesifik ditangkap melalui:
 * - catch (const std::exception& e)
 * - catch (const GachaException& e) (custom exception base class)
 *
 * @note Custom Data Member & Method
 * Sama seperti objek lainnya, Custom Exception juga dapat memiliki data
 * member dan method. Hal ini sangat berguna jika kita ingin membuat handler
 * atau logging yang lebih lengkap dengan konteks tambahan.
 *
 * @note Override what()
 * Kelas std::exception memiliki method virtual:
 *
 * virtual const char* what() const noexcept override;
 *
 * Penjelasan keyword:
 * - const char* : Mengembalikan C-style string, bukan std::string.
 * - const       : Method tidak mengubah state objek.
 * - noexcept    : Method tidak melempar exception.
 *
 * Melempar exception di dalam what() akan menyebabkan program
 * langsung terminate (std::terminate).
 */
class GachaException : public std::exception {
protected:
    int errorCode;
    std::string errorType;

public:
    /**
     * @brief Constructor dari base GachaException.
     * @param code Kode representasi numerik dari error.
     * @param type Nama/tipe kategori dari error.
     */
    GachaException(int code, std::string type) : errorCode(code), errorType(type) {}

    // Custom getter yang aman dengan noexcept
    int getErrorCode() const noexcept {
        return errorCode;
    }

    std::string getErrorType() const noexcept {
        return errorType;
    }

    virtual const char* what() const noexcept override {
        // c_str() mengubah std::string menjadi const char*
        return errorType.c_str();
    }
};

// TODO 1: Buat InsufficientGemsException class (errorCode = 1, errorType = "INSUFFICIENT_GEMS")
class InsufficientGemsException : public GachaException {
public:
    InsufficientGemsException() : GachaException(1, "INSUFFICIENT_GEMS") {};
};

// TODO 2: Buat BannerExpiredException class (errorCode = 2, errorType = "BANNER_EXPIRED")
class BannerExpiredException : public GachaException {
public:
    BannerExpiredException() : GachaException(2, "BANNER_EXPIRED") {};
};

// TODO 3: Buat ItemSoldOutException class (errorCode = 3, errorType = "ITEM_SOLD_OUT")
class ItemSoldOutException : public GachaException {
public:
    ItemSoldOutException() : GachaException(3, "ITEM_SOLD_OUT") {};
};

// * Ketiga exception tersebut juga merupakan GachaException agar bisa polymorphic

#endif
