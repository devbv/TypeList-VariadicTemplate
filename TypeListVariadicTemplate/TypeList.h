#pragma once

struct nulltype {};

template <typename T, typename... Remains>
struct TypeList
{
	typedef T Head;
	typedef TypeList<Remains...> Tail;
};

template <typename T>
struct TypeList<T>
{
	typedef T Head;
	typedef nulltype Tail;
};

template <typename T, typename TL>
struct type_id
{
	enum { value = 1 + type_id<T, typename TL::Tail>::value };
};

template <typename T, typename... S>
struct type_id<T, TypeList<T, S...>>
{
	enum { value = 0 };
};

template <int index, typename TL>
struct type_at
{
	typedef typename type_at<index - 1, typename TL::Tail>::type type;
};

template <typename Head, typename... Tail>
struct type_at<0, TypeList<Head, Tail...>>
{
	typedef Head type;
};

template <typename TL>
struct length
{
	enum { value =  1 + length<TL::Tail>::value };
};

template <>
struct length<nulltype>
{
	enum { value = 0 };
};