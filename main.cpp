#include <iostream>
#include <vector>

class Facultate {
//    std::vector<Student> studenti;
};

class Student {
//private:
    Facultate facultate;
    std::string nume;
    int grupa;
public:
    void setFacultate(Facultate f) {
        facultate = f;
//        this->facultate = f;
//        Student::facultate = f;
    }
    void setNume(std::string nume_) {
        nume = nume_;
    }
    void setGrupa(int gr) {
        grupa = gr;
    }
    Facultate getFacultate() { return facultate; }
    std::string getNume() { return nume; }
    int getGrupa() { return grupa; }
};

int main() {
    Facultate fmi;
    Facultate poli, ase;
    poli = ase;

    Student st;
//    st.facultate = fmi;
    st.setFacultate(fmi);
    std::cout << st.getNume() << " " << st.getGrupa() << "\n";
    st.setGrupa(1511);
    std::cout << st.getNume() << " " << st.getGrupa() << "\n";
    st.setNume("test");
    std::cout << st.getNume() << " " << st.getGrupa() << "\n";
    return 0;
}
