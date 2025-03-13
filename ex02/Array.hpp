/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmodrzej <dmodrzej@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 14:05:15 by dmodrzej          #+#    #+#             */
/*   Updated: 2025/03/13 14:19:43 by dmodrzej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stdexcept>

template <typename T>
class Array
{
	private:
		T* _array;
		unsigned int _size;

	public:
		Array() : _array(NULL), _size(0) {}
		Array(unsigned int n) : _array(new T[n]), _size(n) {}
		Array(const Array &copy) : _array(new T[copy._size]), _size(copy._size)
		{
			for (unsigned int i = 0; i < _size; i++)
			{
				_array[i] = copy._array[i];
			}
		}
		~Array()
		{
			delete[] _array;
		}

		Array &operator=(const Array &copy)
		{
			if (this != &copy)
			{
				delete[] _array;
				_array = new T[copy._size];
				_size = copy._size;
				for (unsigned int i = 0; i < _size; i++)
				{
					_array[i] = copy._array[i];
				}
			}
			return *this;
		}

		T &operator[](unsigned int i)
		{
			if (i >= _size)
			{
				throw std::out_of_range("Index out of range");
			}
			return _array[i];
		}

		unsigned int size() const
		{
			return _size;
		}
};
