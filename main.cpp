#include <iostream>
#include <vector>

//#pragma pack(1)
//#pragma pack(2)
//#pragma pack(3)

class Sala {
};

class Facultate {
//    std::vector<Student> studenti;
    std::string nume = "FMI";
public:
    explicit Facultate(const std::string& nume_) : nume(nume_) {
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

class Materie {
    std::string nume = "OOP";
    const int dificultate = 2;
public:
    Materie(const std::string &nume, int dificultate) : nume(nume), dificultate(dificultate) {
        std::cout << "constr de inițializare materie\n";
    }
    Materie(const Materie& other) : nume(other.nume), dificultate(other.dificultate) {
        std::cout << "constr de copiere materie\n";
    }
    Materie& operator=(const Materie& other) {
        if(this != &other) {
            this->nume = other.nume;
//            this->dificultate = other.dificultate;
        }
        std::cout << "op= materie\n";
        return *this;
    }

    const std::string& getNume() const {
        //this->nume = "aaa";
        return nume;
    }

    ~Materie() {
        std::cout << "destr materie\n";
    }

    friend std::ostream &operator<<(std::ostream &os, const Materie &materie) {
        os << "nume: " << materie.nume << " dificultate: " << materie.dificultate;
        return os;
    }

};

class MaterieObligatorie : Materie {
    int nrPrezente;
public:
    MaterieObligatorie() : Materie("oop", 9), nrPrezente(10) {
        std::cout << "constr de inițializare materie obligatorie\n";
    }
    ~MaterieObligatorie() {
        std::cout << "destr materie obligatorie\n";
    }
    /*MaterieObligatorie(const MaterieObligatorie& other) : Materie(other), nrPrezente(other.nrPrezente) {}
    MaterieObligatorie& operator=(const MaterieObligatorie& other) {
        Materie::operator=(other);
        // static_cast<Materie&>(*this) = other;
        // Materie& materie_ = *this;
        // materie_ = other;
        nrPrezente = other.nrPrezente;
        return *this;
    }*/
    MaterieObligatorie(const std::string &nume, int dificultate, int nrPrezente) : Materie(nume, dificultate),
                                                                                   nrPrezente(nrPrezente) {}

    friend std::ostream &operator<<(std::ostream &os, const MaterieObligatorie &obligatorie) {
        os << static_cast<const Materie &>(obligatorie) << " nrPrezente: " << obligatorie.nrPrezente;
        return os;
    }
};

class Student {
    Facultate facultate{"FMI Unibuc"};
//    Facultate facultate ;//{"FMI Unibuc"};
    std::string nume = "test";
    int grupa = 100;
    std::vector<Materie> materii;
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
    Student(const std::string& nume_, int grupa_) : nume(nume_), grupa(grupa_) {
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

    friend std::ostream &operator<<(std::ostream &os, const Student &student) {
        os << "facultate: " << student.facultate << " nume: " << student.nume << " grupa: " << student.grupa
           << " materii:\n";
        for(const auto& materie : student.materii)
            os << materie;
        return os;
    }
};

void f(Student stud) {
    std::cout << "f: " << stud.getGrupa() << " " << stud.getFacultate() << "\n";
}

Student st_mate() {
    Student tmp{"test 3", 123};
    std::cout << tmp.getNume() << "\n";
    return tmp;
}

class cls1 {
    double v{};
    long long x{};
    int u{};
    char w{};
    char t{};
};


class curs_nv1 {};

class curs_nv2 {
public:
    void f() {}
    void f2() {}
};

class curs_v1 {
public:
    virtual void f() {}
};

class curs_v2 {
public:
    virtual void f() {}
    virtual void g() {}
};

#include <iostream>

class baza {
public:
    virtual void f() { std::cout << "f baza\n"; }
};

class derivata : public baza {
public:
    void f() override { std::cout << "f derivata\n"; }
};

void g1(baza& b) {
    b.f();
}

void g2(baza* b) {
    b->f();
}

void h(baza b) {
    b.f();
}

int main() {
    baza b;
    derivata d;
    std::cout << "----- g1(b) -----\n";
    g1(b);
    std::cout << "----- g2(&b) -----\n";
    g2(&b);
    std::cout << "----- h(b) -----\n";
    h(b);
    std::cout << "----- g1(d) -----\n";
    g1(d);
    std::cout << "----- g2(&d) -----\n";
    g2(&d);
    std::cout << "----- h(d) -----\n";
    h(d);

    std::cout << "sizeof(curs_nv1): " << sizeof(curs_nv1) << "\n";
    std::cout << "sizeof(curs_nv2): " << sizeof(curs_nv2) << "\n";
    std::cout << "sizeof(curs_v1): " << sizeof(curs_v1) << "\n";
    std::cout << "sizeof(curs_v2): " << sizeof(curs_v2) << "\n";
    std::cout << sizeof(Sala) << "\n";
    std::cout << sizeof(cls1) << "\n";
//    return 0;
    MaterieObligatorie oop; // c m, c mo
    Materie m1{"oop", 5}, m2{m1}, m3{m1}; // c m, c m, c m
    // d m, d m, d m, d mo, d m



    m1 = m2 = m3;
    m1.operator=(m2.operator=(m3));


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
    std::cout << fmi; // << " ceva " << st;
    // operator<<(std::cout, fmi);
    // fmi.operator<<(std::cout)
    //fmi << std::cout
    // std::cout.operator<<(fmi);
    std::cout << st << st1 << st4 << sm << st3;
    return 0;
}
