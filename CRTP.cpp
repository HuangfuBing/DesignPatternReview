/*Curiously recurring template pattern.*/

/*The paramter of father template is children.*/

template<class Derived>
class Base{
    //...
};

class Derived : Base<Derived>{
    //编译至"Base<Derived>"部分时，实例化类模板Base，得到一个实例化的类，非递归。
    /*
        在类模板Base中就可以得到子类的信息，实现静态多态。
        避免动态多态的小缺点：每个类都要定义虚函数，晚绑定消耗时间。
    */
    //...
};

//Example

class Shape{
    public:
    virtual ~Shape(){}
    virtual Shape* clone() const = 0;
};

template<typename Derived>
class Shape_CRTP: public Shape{
    public:
    virtual Shape* clone() const{
        //e.g. i = static_cast<int>(f)----->Transform float to int.
        return new Derived(static_cast<Derived const&>(*this));
    }
};

class Square: public Shape_CRTP<Square>{};
class Circle: public Shape_CRTP<Circle>{};
