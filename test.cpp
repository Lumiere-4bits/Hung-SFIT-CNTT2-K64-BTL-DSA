#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Student {
private:
    string id;
    string name;
    int age;
    float score;

public:
    Student(string id, string name, int age, float score)
        : id(id), name(name), age(age), score(score) {}

    friend istream& operator>>(istream& in, Student& s) {
        cout << "Nhap ma sinh vien: ";
        in >> s.id;
        cout << "Nhap ten sinh vien: ";
        in.ignore();
        getline(in, s.name);
        cout << "Nhap tuoi: ";
        in >> s.age;
        cout << "Nhap diem: ";
        in >> s.score;
        return in;
    }

    friend ostream& operator<<(ostream& out, const Student& s) {
        out << "Ma: " << s.id << "\t| Ten: " << s.name << "\t| Tuoi: " << s.age << "\t| Diem: " << s.score;
        return out;
    }

    bool operator<(const Student& other) const {
        return this->score < other.score;
    }

    string getId() const { return id; }
    float getScore() const { return score; }
};


class StudentList {
private:
    vector<Student> students;

public:
    void addStudent(const Student& student) {
        students.push_back(student);
    }

    void removeStudentById(const string& id) {
        students.erase(remove_if(students.begin(), students.end(),
            [&](const Student& s) { return s.getId() == id; }), students.end());
    }

    void sortStudents() {
        sort(students.begin(), students.end());
    }

    Student findMaxScore() {
        return *max_element(students.begin(), students.end());
    }

    Student findMinScore() {
        return *min_element(students.begin(), students.end());
    }

    Student* searchStudentById(const string& id) {
        for (auto& student : students) {
            if (student.getId() == id) return &student;
        }
        return nullptr;
    }

    void displayStudents() const {
        for (const auto& student : students) {
            cout << student << endl;
        }
    }
};

class App {
public:
    void run() {
        int choice;
        StudentList studentList;
        do {
            cout << "\n----- MENU -----\n";
            cout << "1. Them sinh vien\n";
            cout << "2. Xoa sinh vien theo ma\n";
            cout << "3. Sap xep danh sach\n";
            cout << "4. Tim sinh vien diem cao nhat\n";
            cout << "5. Tim sinh vien diem thap nhat\n";
            cout << "6. Tim kiem sinh vien theo ma\n";
            cout << "7. Hien thi danh sach\n";
            cout << "0. Thoat\n";
            cout << "Lua chon cua ban: ";
            cin >> choice;

            switch (choice) {
                case 1: {
                    int n;
                    cout << "Nhap so sinh vien can them: ";
                    cin >> n;
                    for(int i = 0; i < n; i++){
                        cout<< "Nhap sinh vien thu " << i + 1 << endl;
                        Student s("", "", 0, 0);
                        cin >> s;
                        studentList.addStudent(s);
                    }
                    break;
                }
                case 2: {
                    string id;
                    cout << "Nhap ma sinh vien can xoa: ";
                    cin >> id;
                    studentList.removeStudentById(id);
                    break;
                }
                case 3:
                    studentList.sortStudents();
                    cout << "Danh sach da duoc sap xep." << endl;
                    break;
                case 4: {
                    Student maxScoreStudent = studentList.findMaxScore();
                    cout << "Sinh vien co diem cao nhat: " << maxScoreStudent << endl;
                    break;
                }
                case 5: {
                    Student minScoreStudent = studentList.findMinScore();
                    cout << "Sinh vien co diem thap nhat: " << minScoreStudent << endl;
                    break;
                }
                case 6: {
                    string id;
                    cout << "Nhap ma sinh vien can tim: ";
                    cin >> id;
                    Student* foundStudent = studentList.searchStudentById(id);
                    if (foundStudent) {
                        cout << "Thong tin sinh vien tim thay: " << *foundStudent << endl;
                    } else {
                        cout << "Khong tim thay sinh vien co ma: " << id << endl;
                    }
                    break;
                }
                case 7:
                    studentList.displayStudents();
                    break;
                case 0:
                    cout << "Thoat chuong trinh." << endl;
                    break;
                default:
                    cout << "Lua chon khong hop le." << endl;
            }
        } while (choice != 0);
    }
};

int main() {
    App app;
    app.run();
    return 0;
}
