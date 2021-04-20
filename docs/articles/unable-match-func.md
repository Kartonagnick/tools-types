
Кратко:
------
Баг msvc2008 и msvc2010  

Описание проблемы:
------            
Следующий код корректный, но msvc2008/msvc2010 не могут его скомпилировать:  

```cpp
struct dummy;

template <bool, class = void>
struct if_ {};

template <class t>
struct if_<true, t> { typedef t type; };

template <class t, class u>
struct same_ { enum { value = 0 }; };

template <class t>
struct same_ <t, t> { enum { value = 1 }; };

template<class t, class u> struct help_
{
    enum { v = same_<t, u>::value };
    typedef if_<!v, dummy*>
        if_t;
    typedef typename if_t::type
        type;
};

// msvc2008: not worked
// msvc2010: not worked
#define impl(t,u) \
    typename if_< ! same_<t,u>::value, dummy*>::type
    
#define decl(t,u) \
    impl(t,u) = 0

struct example
{
    template<class A>
    example(const A&, decl(A, example));
    example(const example&);
    example();
};

template<class A>
example::example(const A& a, impl(A, example)) {}

int main(){}
```

Ошибка:  
```
error C2244: 'example::{ctor}' : unable to match function definition to an existing declaration
```

## Лекарство
Рекомендация от Microsoft:  
`To work around this problem, try simplifying or changing the program near the locations listed above.`

Упростим конструкцию:  

```cpp11
struct dummy;

template <bool, class = void>
struct if_ {};

template <class t>
struct if_<true, t> { typedef t type; };

template <class t, class u>
struct same_ { enum { value = 0 }; };

template <class t>
struct same_ <t, t> { enum { value = 1 }; };

template<class t, class u> struct help_
{
    enum { v = same_<t, u>::value };
    typedef if_<!v, dummy*>
        if_t;
    typedef typename if_t::type
        type;
};

#define impl(t,u) \
    typename help_<t,u>::type
    
#define decl(t,u) \
    impl(t,u) = 0

struct example
{
    template<class A>
    example(const A&, decl(A, example));
    example(const example&);
    example();
};

template<class A>
example::example(const A& a, impl(A, example)) {}
```
