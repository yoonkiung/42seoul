/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiyoon <kiyoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 10:48:49 by kiyoon            #+#    #+#             */
/*   Updated: 2022/02/27 10:48:50 by kiyoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	swap_arr(int arr[], int a, int b)
{
	int	temp;

	temp = arr[a];
	arr[a] = arr[b];
	arr[b] = temp;
}

int	partition(int arr[], int left, int right)
{
	int	pivot;
	int	low;
	int	high;

	pivot = arr[left];
	low = left + 1;
	high = right;
	while (low <= high)
	{
		while (low <= right && pivot >= arr[low])
			low++;
		while (high >= (left + 1) && pivot <= arr[high])
			high--;
		if (low <= high)
			swap_arr(arr, low, high);
	}
	swap_arr(arr, left, high);
	return (high);
}

void	quicksort(int arr[], int left, int right)
{
	int	pivot;

	if (left <= right)
	{
		pivot = partition(arr, left, right);
		quicksort(arr, left, pivot - 1);
		quicksort(arr, pivot + 1, right);
	}
}
