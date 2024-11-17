#include<iostream>
#include<string>
#include<fstream>


using namespace std;

template<class T>
class Vector{
private:
    T* data;
    int size;
    int cap;
public:
    Vector(): size(0), cap(1){
        data = new T[cap];
    }
    ~Vector(){
        delete[] data;
    }
    int getSize(){
        return size;
    }
    void resize(int new_size){
        if(new_size <= cap) return;
        cap = new_size;
        T* new_data = new T[cap];
        for(int i = 0; i < size; i++){
            new_data[i] = data[i];
        }
        delete[] data;
        data = new_data;
    }
    void push_back(const T& value){
        if(size == cap){
            cap *= 2;
            T* new_data = new T[cap];
            for(int i = 0; i < size; i++){
                new_data[i] = data[i];
            }
            delete[] data;
            data = new_data;
        }
        data[size++] = value;
    }
    T& operator[](int index){
        return data[index];
    }
    void display() const {
        for(int i = 0; i < size; i++){
            cout << data[i] << endl;
        }
    }
    void erase(const T& value){
        int index = -1;
        for(int i = 0; i < size; i++){
            if(data[i] == value){
                index = i;
                break;
            }
        }
        if(index != -1){
            for(int i = index; i < size - 1; i++){
            data[i] = data[i + 1];
            }
            --size;
        }else{
            cout << "Not found" << endl;
        }
    }
    void insert(int index, const T& value){
        if(index < 0 || index > size){
            cout << "Out of range" << endl;
            return;
        }
        if(size == cap){
            cap *= 2;
            T* new_data = new T[cap];
            for(int i = 0; i < size; i++){
                new_data[i] = data[i];
            }
            delete[] data;
        }
        for(int i = size; i > index; i--){
            data[i] = data[i - 1];
        }
        data[index] = value;
        ++size;
    }
    void clear(){
        size = 0;
    }
    void assign(int count, const T& value){
        if(count > cap){
            resize(count);
        }
        for(int i = 0; i < count; i++){
            data[i] = value;
        }
        size = count;
    }
    void reserve(int new_cap){
        if(new_cap > cap){
            resize(new_cap);
        }
    }
    bool empty() const{
        return size == 0;
    }
};

class Products{
private:
    string product_id;
    string product_name;
    string producer;
    int number;
public:
    Products(): product_id(""), product_name(""), producer(""), number(0){}
    Products(string id, string name, string pro, int n): product_id(id), product_name(name), producer(pro), number(n){}
    void display(){
        cout << product_id << "\t|" << product_name << "\t|" << producer << "\t|" << number << endl;   
    }
    string get_product_id(){
        return product_id;
    }
    string get_product_name(){
        return product_name;
    }
    string get_producer(){
        return producer;
    }
    int get_nums(){
        return number;
    }
    void set_nums(int num){
        this->number = num;
    }
    bool operator==(const Products& p) const{
        return product_id == p.product_id;
    }
    friend ostream& operator<<(ostream& os, const Products& p){
        os << p.product_id << "\t|" << p.product_name << "\t|" << p.producer << "\t|" << p.number << endl;
        return os;
    }
    friend istream& operator>>(istream& is, Products& p){
        cout << "Enter Product-Id: ";
        is >> p.product_id;
        cout << "Enter Product-Name: ";
        is >> p.product_name;
        cout << "Enter Producer: ";
        is >> p.producer;
        cout << "Enter Number: ";
        is >> p.number;
        return is;
    }
    friend ofstream& operator<<(ofstream& os, const Products& p){
        os << p.product_id << "," << p.product_name << "," << p.producer << "," << p.number << endl;
        return os;
    }
    friend ifstream& operator>>(ifstream& is, Products& p){
        getline(is, p.product_id, ',');
        getline(is, p.product_name, ',');
        getline(is, p.producer, ',');
        is >> p.number;
        is.ignore();
        return is;
    }
};

class Bills{
private:
    string bill_id;
    string product_id;
    string bill_type;
    int num;
    int date;
    int price;
public:
    Bills(): bill_id(""), product_id(""), bill_type(""), num(0), date(0), price(0){}
    Bills(string id, string pro_id, string type, int n, int d, int p): bill_id(id), product_id(pro_id), bill_type(type), num(n), date(d), price(p){}
    void display(){
        cout << bill_id << "\t|" << product_id << "\t|" << bill_type << "\t|" << num << "\t|" << date << "\t|" << price << endl;
    }
    string get_product_id(){
        return product_id;
    }
    string get_bill_type(){
        return bill_type;
    }
    int get_num(){
        return num;
    }
    int get_date(){
        return date;
    }
    int get_price(){
        return price;
    }
    friend ostream& operator<<(ostream& os, const Bills& b){
        os << b.bill_id << "\t|" << b.product_id << "\t|" << b.bill_type << "\t|" << b.num << "\t|" << b.date << "\t|" << b.price;
        return os;
    }
    friend istream& operator>>(istream& is, Bills& b){
        cout << "Enter Bill-Id: ";
        is >> b.bill_id;
        cout << "Enter Product-Id: ";
        is >> b.product_id;
        cout << "Enter Bill-Type: ";
        is >> b.bill_type;
        cout << "Enter Number: ";
        is >> b.num;
        cout << "Enter Date: ";
        is >> b.date;
        cout << "Enter Price: ";
        is >> b.price;
        return is;
    }
    friend ofstream& operator<<(ofstream& os, const Bills& b){
        os << b.bill_id << "," << b.product_id << "," << b.bill_type << "," << b.num << "," << b.date << "," << b.price << endl;
        return os;
    }
    friend ifstream& operator>>(ifstream& is, Bills& b){
        getline(is, b.bill_id, ',');
        getline(is, b.product_id, ',');
        getline(is, b.bill_type, ',');
        is >> b.num;
        is.ignore();
        is >> b.date;
        is.ignore();
        is >> b.price;
        is.ignore();
        return is;
    }

};

class Store{
private:
    Vector<Products> products;
    Vector<Bills> bills;
    Vector<Products> new_products;
    Vector<Bills> new_bills;
public:
    void get_data(const string& filename, bool isProducts){
        ifstream file(filename);
        if(!file){
            cout << "Cannot open file" << endl;
            return;
        }
        if(isProducts){
            Products p;
            while(file >> p){
                products.push_back(p);
            }
        }
        else{
            Bills b;
            while(file >> b){
                bills.push_back(b);
            }
        }
        file.close();
    }
    void write_data(const string& filename, bool isProducts){
        ofstream file(filename);
        if(!file){
            cout << "Cannot open file" << endl;
            return;
        }
        if(isProducts){
            if(products.getSize() == 0){
                cout << "No products" << endl;
            }
            for(int i = 0; i < products.getSize(); i++){
                file << products[i];
            }
        }
        else{
            if(bills.getSize() == 0){
                cout << "No bills" << endl;
            }
            for(int i = 0; i < bills.getSize(); i++){
                file << bills[i];
            }
        }
        file.close();
    }
    void input_products(){
        int n;
        cout << "Enter number of products: ";
        cin >> n;
        if(n <= 0){
            return;
        }
        for(int i = 0; i < n; i++){
            Products p;
            cin >> p;
            products.push_back(p);
            new_products.push_back(p);
        }
        cout << "Added products" << endl;
    }
    void display_products(){
        if(new_products.getSize() == 0){
            cout << "No products" << endl;
        }else{
            cout << "Products:" << endl;
            new_products.display();
        }
    }
    void input_bills(){
        int n;
        cout << "Enter number of bills: ";
        cin >> n;
        if(n <= 0){
            return;
        }
        for(int i = 0; i < n; i++){
            Bills b;
            cin >> b;
            bills.push_back(b);
            new_bills.push_back(b);
        }
        cout << "Added bills" << endl;
    }
    void display_bills(){
        if(new_bills.getSize() == 0){
            cout << "No bills" << endl;
        }else{
            cout << "Bills:" << endl;
            new_bills.display();
        }
        
    }
    void display_product(const string& filename){
        ifstream file(filename);
        if(!file){
            cout << "Cannot open file" << endl;
            return;
        }
        Products p;
        cout << "Products from file:" << endl;
        while(file >> p){
            p.display();
        }
        file.close();
        if(new_products.getSize() == 0){
            cout << "No new products" << endl;
        }else{
            cout << "New products: " << endl;
            new_products.display();
        }
    }
    void statisticals(){
        cout << "Statisticals:" << endl;
        for(int i = 0 ; i < products.getSize(); i++){
            int number_exist = 0;
            for(int j = 0; j < products.getSize(); j++){
                if(products[i].get_product_id() == products[j].get_product_id()){
                    number_exist += products[j].get_nums();
                }
            }
            for(int j = 0; j < new_products.getSize(); j++){
                if(new_products[j].get_product_id() == products[i].get_product_id()){
                    number_exist += new_products[j].get_nums();
                }
            }
            for(int j = 0; j < bills.getSize(); j++){
                if(bills[j].get_product_id() == products[i].get_product_id()){
                    number_exist -= bills[j].get_num();
                }
            }
            cout << "Product-Id: " << products[i].get_product_id() << "\t| Product-Name: " << products[i].get_product_name() << "\t| Number: " << number_exist << endl;
        }
        if(new_products.getSize() == 0){
            cout << "No new products" << endl;
        }
        for(int i = 0; i < new_products.getSize(); i++){
            bool found = false;
            for(int j = 0; j < products.getSize(); j++){
                if(new_products[i].get_product_id() == products[j].get_product_id()){
                    found = true;
                    break;
                }
            }
            if(!found){
                int number_exist = new_products[i].get_nums();
                for(int j = 0; j < bills.getSize(); j++){
                    if(bills[j].get_product_id() == new_products[i].get_product_id()){
                        number_exist -= bills[j].get_num();
                    }
                }
                cout << "Product-Id: " << new_products[i].get_product_id() << "\t| Product-Name: " << new_products[i].get_product_name() << "\t| Number: " << number_exist << endl;
            }
        }
    }
};

int main(){
    Store store;

    store.get_data("products.txt", true);
    store.get_data("bills.txt", false);
    // do a list of choice
    int choice;
    do{
        cout << "1. Input products" << endl;
        cout << "2. Display products" << endl;
        cout << "3. Input bills" << endl;
        cout << "4. Display bills" << endl;
        cout << "5. Display products-list" << endl;
        cout << "6. Statisticals" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch(choice){
            case 1:
                store.input_products();
                store.write_data("output1.txt", true);
                break;
            case 2:
                store.display_products();
                break;
            case 3:
                store.input_bills();
                store.write_data("output2.txt", false);
                break;
            case 4:
                store.display_bills();
                break;
            case 5:
                store.display_product("products.txt");
                break;
            case 6:
                store.statisticals();
                break;
            case 7:
                cout << "Exit" << endl;
                break;
            default:
                cout << "Invalid choice" << endl;
                break;
        }        
    }while(choice != 7);
}
