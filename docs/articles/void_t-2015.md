
Кратко:
------
Дефект в поведении msvc2015.


Описание проблемы:
------            
Visual Studio 2015 не проходит static_assert:

```cpp

template<class, class = void>
struct end : ::std::false_type {};

template<class t> struct end<t, 
        std::void_t<decltype(::std::declval<t>().end())>
    > : ::std::true_type
{};

struct Const { void end() const; };

int main()
{
    static_assert(end<Const>::value, "bug");
}
```

## Лекарство
Для msvc2015 используется самодельный void_t

```
namespace tools 
{
    namespace detail_void
    {
        template<class...> struct check_params_
            { typedef void type; };

    } // namespace detail_void

    template<class... args>
    using void_t
        = typename detail_void::check_params_<args...>::type;

} // namespace tools 
```
