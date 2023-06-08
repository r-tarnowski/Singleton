#include <iostream>
#include <string>


using std::cout;
using std::endl;

void printHeader() {
   cout << endl;
   cout << "================================================" << endl;
   cout << "Design Patterns in Modern C++ by Dmitri Nesteruk" << endl;
   cout << "                  Singleton                     " << endl;
   cout << "================================================" << endl;
   cout << endl;
}

class Database {
protected:
    Database() {
        std::cout << "Database () constructor called." << std::endl;
    }

public:

    ~Database() {
      std::cout << "~Database () destructor called." << std::endl;
    }

    static Database & get() {
        static Database database;
        return database;
    }

    void service() {
        std::cout << "Database service called." << std::endl;
    }

    Database( Database const & ) = delete;
    Database( Database && ) = delete;
    Database & operator=( Database const & ) = delete;
    Database & operator=( Database && ) = delete;

};

int main(int argc, char *argv[]) {
   printHeader();

   std::cout << "Trying to get reference myDatabase1:" << std::endl;
   Database & myDatabase1 = Database::get();
   myDatabase1.service();

   std::cout << "Trying to get reference myDatabase2:" << std::endl;
   Database & myDatabase2 = Database::get();
   myDatabase2.service();

   std::cout << "Completed." << std::endl;
   return 0;
}
