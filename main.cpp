#include <iostream>
#include <vector>

class Facultate {
//    std::vector<Student> studenti;
    std::string nume = "FMI";
public:
    Facultate(std::string nume_) : nume(nume_) {
        std::cout << "constr de initializare facultate\n";
    }
    Facultate(const Facultate& other) : nume(other.nume) {
        std::cout << "constr copiere facultate\n";
    }
    Facultate& operator=(const Facultate& other) {
        std::cout << "op= facultate\n";
        nume = other.nume;
        return *this;
    }
    ~Facultate() {
        std::cout << "destr facultate\n";
    }
    friend std::ostream& operator<<(std::ostream& os, const Facultate& facultate) {
        os << "Facultate: [" << facultate.nume << "]\n";
        return os;
    }
};

class Student {
    Facultate facultate{"FMI Unibuc"};
//    Facultate facultate ;//{"FMI Unibuc"};
    std::string nume = "test";
    int grupa = 100;
public:
//     Student() : facultate("FMI Unibuc") {
    Student() {
        std::cout << "constr implicit\n";
    }
//    Student(const Student& other) : facultate(other.facultate), nume(other.nume), grupa(other.grupa) {
//    Student(const Student& other) : facultate("") {
    Student(const Student& other) {
        std::cout << "constr copiere student begin\n";
        this->facultate = other.facultate;
        this->nume = other.nume;
        this->grupa = other.grupa;
        std::cout << "constr copiere student end\n";
    }
    Student(std::string nume_, int grupa_) : nume(nume_), grupa(grupa_) {
//        nume = nume_;
//        grupa = grupa_;
        std::cout << "constr student\n";
    }
    void setGrupa(int gr) {
        grupa = gr;
    }
    Facultate getFacultate() { return facultate; }
    std::string getNume() { return nume; }
    int getGrupa() { return grupa; }
    friend std::ostream& operator<<(std::ostream& os, const Student& st) {
        os << "op<< stud: " << st.facultate << " " << st.nume << " " << st.grupa << "\n";
        return os;
    }
};

void f(Student stud) {
    std::cout << "f: " << stud.getGrupa() << "\n";
}

Student st_mate() {
    Student tmp{"test 3", 123};
    std::cout << tmp.getNume() << "\n";
    return tmp;
}

int main() {
    Facultate fmi{"FMI"}, fmi_cluj = fmi;
    Facultate poli{"Poli"}, ase{"Ase"};
    poli = ase;

    Student st;
    Student st1{"test 2", 1511};
    f(st1);
    std::cout << "înainte de apel st_mate\n";
//    Student sm = st_mate();
    Student sm{st_mate()};
    Student st3 = st;
    Student st4{st1};

    std::cout << "după apel st_mate\n";
//    st.facultate = fmi;5
//    st.setFacultate(fmi);
    std::cout << st.getNume() << " " << st.getGrupa() << "\n";
    std::cout << st1.getNume() << " " << st1.getGrupa() << "\n";
    st.setGrupa(1511);
    std::cout << st.getNume() << " " << st.getGrupa() << "\n";
//    st.setNume("test");
    std::cout << st.getNume() << " " << st.getGrupa() << "\n";
    std::cout << fmi;
    std::cout << st << st1 << st4;
    return 0;
}
