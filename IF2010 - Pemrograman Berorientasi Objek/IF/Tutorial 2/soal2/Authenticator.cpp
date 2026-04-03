#include "Authenticator.hpp"

Authenticator::Authenticator(): currentUser(nullptr), secretResource("Ini adalah data rahasia!"), userCount(0) {}
void Authenticator::registerUser(const string &username, const string &password, bool isAdmin) {
    if(userCount == MAX_USERS) {
        cout << "Gagal: Kapasitas user penuh!\n";
        return;
    }
    bool exist = false;
    for(int i = 0; i < userCount && !exist; i++) {
        if(users[i]->getUsername() == username) exist = true;
    }
    if(exist) {
        cout << "Gagal: Username sudah digunakan!\n";
        return;
    }

    if(isAdmin) {
        AdminUser* newAdmin = new AdminUser(username, password);
        users[userCount] = newAdmin;
    }
    else {
        User* newUser = new User(username, password);
        users[userCount] = newUser;
    }
    
    userCount++;
    cout << "Sukses: User "<< username <<" berhasil terdaftar!\n";
}

void Authenticator::login(const string &username, const string &password) {
    int exist = -1;
    for(int i = 0; i < userCount && exist < 0; i++) {
        if(users[i]->getUsername() == username) exist = i;
    }

    if(exist < 0) {
        cout << "Gagal: Username atau password salah!\n";
        return;
    }
    if(!users[exist]->checkPassword(password)) {
        cout << "Gagal: Username atau password salah!\n";
        return;
    }

    currentUser = users[exist];

    cout << "Sukses: Login berhasil! Selamat datang, " << username <<".\n";
}

void Authenticator::logout() {
    if(!currentUser) {
        cout << "Gagal: Tidak ada user yang sedang login!\n";
        return;
    }
    cout << "Sukses: User " << currentUser->getUsername() << " telah logout.\n";
    currentUser = nullptr;
}

void Authenticator::accessResource() const {
    if(!currentUser) {
        cout << "Akses ditolak! Silakan login terlebih dahulu.\n";
        return;
    }

    cout << "Resource: " << secretResource << "\n";
}

void Authenticator::setResource(const string &newResource) {
    if(!currentUser) {
        cout << "Gagal: Tidak bisa mengubah resource! Silakan login terlebih dahulu.\n";
        return;
    }
    if(!currentUser->isAdmin()) {
        cout << "Gagal: Tidak bisa mengubah resource! Hanya admin yang dapat melakukan ini.\n";
        return;
    }
    secretResource = newResource;
    cout << "Sukses: Resource telah diperbarui oleh "<< currentUser->getUsername() << ".\n";
}

Authenticator::~Authenticator() {
    for(int i = 0; i < userCount; i++) {
        delete users[i];
    }
}