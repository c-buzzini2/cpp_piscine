/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbuzzini <cbuzzini@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/12 09:53:10 by cbuzzini          #+#    #+#             */
/*   Updated: 2026/08/12 11:53:51 by cbuzzini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

template <typename T>
Array<T>::Array(void) : _arr(NULL), _size(0)
{
}

template <typename T>
Array<T>::Array(unsigned int n) : _arr(new T[n]), _size(n)
{
}

template <typename T>
Array<T>::Array(Array& src) : _arr(new T[src._size]), _size(src._size)
{
    for (int i = 0; i < _size ; i++)
		_arr[i] = src._arr[i];
}

template <typename T>
Array<T>::~Array(void)
{
    delete [] _arr;
}

template <typename T>
Array<T>& Array<T>::operator=(Array<T>& src)  
{
	if (this != &src)
	{	
		delete [] _arr;
		_arr = new T[src._size];
		_size = src._size;
		
		for (int i = 0; i < _size ; i++)
			_arr[i] = src._arr[i];
		
	}
	return (*this);
}

template <typename T>
const Array<T>& Array<T>::getArray(void) const
{
	return (_arr);
}

template <typename T>
const size_t& Array<T>::size(void) const
{
	return (_size);
}

template <typename T>
T& Array<T>::operator[](int idx)
{
	if (_size == 0 || idx < 0 || static_cast<size_t>(idx) > _size - 1)
	{
		throw (OutOfBounds());
	}
	return(_arr[idx]);
}

template <typename T>
const char* Array<T>::OutOfBounds::what(void) const throw()
{
	return ("index out of bounds\n");
}
