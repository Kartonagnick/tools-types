
������:
------
�������� msvc2013 � ����� ������ ������������, 
��� ����� ����� ���� ����� �������������.  


�������� ��������:
------            
� Visual Studio 2013 �� �������� ������ `std::void_t`

��������� ��� ��������� � ����� ������ ������ �����.
�� ������ msvc2013 ������� �� static_assert:

```cpp
#include <type_traits>
#include <iostream>
#include <string>
#include <vector>
#include <map>
 
namespace util
{
    template<class...> using void_t = void;
 
} // namespace util
 
typedef std::string       str_t;
typedef std::vector<int>  vec_t;
typedef std::map<int,int> map_t;
  
template<class, class = void>
struct has_value_type
    : std::integral_constant<bool, false>
{};
 
template<class T>
struct has_value_type<T, util::void_t<typename T::value_type> > 
    : std::integral_constant<bool, true>
{};

// error C2338
static_assert(!has_value_type<int>::value, "INT_ERROR"); 
 
static_assert(has_value_type<str_t>::value, "VEC_ERROR");
static_assert(has_value_type<vec_t>::value, "MAP_ERROR");
 
int main()
{
    std::cout << "[ALL TESTS PASSED]\n";
}
```
����� �� ��� �� ���� ��������� `msvc2013` � `std::void_t` ?


�������
------
��� �� ������ ��� ��������, ����� ������� ������ ���� ���� ��������.  
� ��� �� ������ � ��� ���� ��������, ����� ������� ������ ������� �������� ������� `void_t`  
� ��� ����, ��� �� ������ ������� �������� ������� `void_t`, 
����� ������� ������ "������� ��������������� ������������� ������� �� ���������"  


����, ������ �� �������.  

## ������� ��������������� ������������� ������� �� ���������

������:  
������� ���������� ����������� �������� �� ���������,
� ����� ���������: ���� ���������� ����� ���������� ������������� �������������,
����� �� ������������ ��� �������������,
� ��������� ������ �������������� ������� ������.  
����� �������, �� ��������� ������ ����������� �������������, � �� ������� ������.  

```cpp
#include <iostream>
 
template<class t, bool = true>
struct example
{
    example() noexcept { std::cout << "general\n"; }
};
 
template<class t>
struct example<t, true>
{
    example() noexcept { std::cout << "example<t,true>\n"; }
};
 
int main()
{
    example<int> ex; // example<t,true>
}
```
���� �� ������� ������ ��������, �� �� ��������� �� ����� `true`,
��� ������������� �������������, � ������ ��� � ����� � ����� ��������������.  

## void_t
������������ ����� ����� � ����� `void`

```cpp
namespace std
{
    template<class...> using void_t = void;
 
} // namespace std
```

�� �������� ����� �++, ��������� ���� � ��� ��� - ��� ���� � ����.
������� �������, `std::void_t<����� ���������>` - �� ����� ���� �������� ������ `void`  

������ ���������� ������������ ������ ������������� ������� �� ��������:  

```cpp
#include <type_traits>
#include <string>
 
template<class, class = void> struct has_value_type
    : std::false_type
{};
 
template<class T> 
struct has_value_type<T, std::void_t<typename T::value_type> > 
    : std::true_type
{};
 
static_assert(has_value_type<std::string>::value, "ERROR");
int main(){}
```

�� ��� �����, ��� ���� ���� �� ������� �������� �� ���������,
�� ���������� ���������� �������������� ��������� �������������.  
� ������ ������ ���������� ����� ������ ������������� `<T,void>`  

� ��������� `std::void_t<typename T::value_type>` � ���� `void`,
�� ������ ��� ������������� � ���������� �������������� ���������� �� ���������:  

```cpp
template<class T> 
struct has_value_type<T, std::void_t<typename T::value_type> > 
    : std::true_type
{};
```

��(!) � ����� ��������: ��� ������ `std::void_t<typename T::value_type>` ������ ���� ��������.  
� �������� �� ����� ���� ������ � ������ � ��� ������, ���� ������ `T` �������� ��������� ��� `value_type`  
���� �� ��� ������� �� �����������, 
����� ��� ������������� `has_value_type<T, std::void_t<typename T::value_type> >` ���������� ��_��������,
� �������� �� �������� �� ���������������.  

� ���� ������, �������� �������� SFINAE, ���������� ������ ������� ��������� ������������ ������� ������:  
```
template<class, class = void> struct has_value_type
    : std::false_type
{};
```

## C��� �������� msvc2013
��������� ��� ������������ ���� ��������:  

```cpp
template<class T, class VT = typename T::value_type> 
using enable_if_has_value_type_t = void;
 
template<class T, class = void>
struct has_value_type : std::false_type {};
 
template<class T>
struct has_value_type<T, enable_if_has_value_type_t<T> > 
  : ::std::true_type {};    
 
static_assert(!has_value_type<int>::value, "ERROR"); // upppssss
int main(){}
```

��� ����� ���������?  
���������� ������� ������������� ������������� `true_type`,
�������� �� ��, ��� ������ `class VT = typename T::value_type` ������������� ��_���������.  

��� ��������� ������, ��� ���������� � �� ������� ���������� `typename T::value_type`  
��� ��� ����������� ������� �� �����:  

```
namespace std
{
    template<class...> using void_t = void;
 
} // namespace std
```
��� � � ������� ����: `using enable_if_has_value_type_t = void`, 
�������� ��������� ��_������� �� ���������� �������.  
������ ������������ (msvc2013 ��� ����� ������) ��� ��� ��������� ������ ���� �� "�������" ����������,
� ����� ��, ����� ������ �������� ��������� - `void`  

���-�� ������: �� ���� ��������� ������� ����� ���� �������!  
������ ��� ���������� �� �� ���������?  

�� ��� � ��������� ���� �������������� �������: ����� ���������, � ����� � ���� ���������.  
� ������ ������ ����� - ����� � ���� UB, � ����� ���� ������ �� ������.  

���������� ����� ������ ����� ������������� �� ��,
��� ����������� - �� �����, � ������ �� ����� ������ ������ ����.  

������ ������� ��� ���������� msvc2013 �������� ���.  
������ ��� ��� ���������� `�++11` ����� ��������� ���� ����������.  
�� � ���������� ����� ��������� ���� ���� �������� ��������,
� � ��������� ������ ����������� ���� ������� ������������ ��������� � `SFINAE` ���������.  

���������� �������� ��������:  
��� ������������ ������������ `std::void_t` ���������� `�++11`, 
�� ��� ����, ��� �� ��� �������� ��������, ��������� ��������� `�++17`

## ���������
����� ������� � ��������� ������� - ������������ �������������.  

```
������������� - ������� �����������, ������� ������ ���� ����������� ����� �������,
�� ��� ���� �������� ��������� ������� ��� ���������.
```

C ������� �������������� ����� ��������� ���������� ������ ��������� ��� ��������� �������:  

```cpp
#include <type_traits>
 
namespace util
{
    template<class... Args> struct discriminator
        { enum { value = 1 }; };

    template<class A, class... Args> struct discriminator_<A, Args...>
        { 
            using x = ::std::detail::discriminator_<Args...>;
            enum { v = ::std::is_same<A, A>::value };
            enum { value = v && x::value };
        };
 
    template<class... Args> 
        using void_t = ::std::enable_if_t< discriminator<Args...>::value >;
 
} // namespace util
 
 
template<class, class = void>
struct has_value_type
    : std::integral_constant<bool, false>
{};
 
template<class T>
struct has_value_type<T, util::void_t<typename T::value_type> > 
    : std::integral_constant<bool, true>
{};
 
#include <iostream>
#include <vector>
#include <string>
#include <map>
 
using str_t = std::string;
using vec_t = std::vector<int>;
using map_t = std::map<int,int>;
 
static_assert(has_value_type<str_t>::value, "STR_ERROR");
static_assert(has_value_type<vec_t>::value, "VEC_ERROR");
static_assert(has_value_type<map_t>::value, "MAP_ERROR");
static_assert(!has_value_type<int>::value , "INT_ERROR");
 
int main()
{
    std::cout << "[ALL TESTS PASSED]\n";
}
```

� ���� �������, ��� �� ��������� �������� `void_t`,
���������� �������� �������������� �������������,
������� � ���� ������� ������� ���������� ���� ���������� �������,
��� � ���� ������� �� ��������� ����������� �� ���������������.

`PROFIT???!!!!`
