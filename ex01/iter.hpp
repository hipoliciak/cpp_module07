/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmodrzej <dmodrzej@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 13:44:47 by dmodrzej          #+#    #+#             */
/*   Updated: 2025/03/13 13:56:10 by dmodrzej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

template <typename T>
void iter(T* array, size_t length, void (*f)(T &))
{
	for (size_t i = 0; i < length; i++)
	{
		f(array[i]);
	}
}
