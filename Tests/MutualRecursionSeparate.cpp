//by Ilya Mirzazhanov
//unanticipated mutual recursion
//polystat can detect it
//clang can not
class Class1;
class Class2;

// Class1 recursively uses method of Class2
class Class1 {
  Class2* Class2_ptr;
public:
  void Class1_method();
};

// Class2 recursively uses method of Class1
class Class2 {
  Class1* Class1_ptr;
public:
  void Class2_method();
};

//unanticipated mutual recursion happens here
void Class1::Class1_method() {
  (*Class2_ptr).Class2_method();
}

// 
void Class2::Class2_method() {
  (*Class1_ptr).Class1_method();
}
int main(){}