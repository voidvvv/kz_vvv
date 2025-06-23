#ifndef __ALGORITHM_H__
#define __ALGORITHM_H__
#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#include "LRUCache.h"
#include "ListNode.h"

int add(int a, int b);
std::vector<int> twoSum(std::vector<int> &nums, int target);
int trap(std::vector<int> &height);
void setZeroes(std::vector<std::vector<int>> &matrix);

/**
 * 给定一个长度为 n 的整数数组 height 。有 n 条垂线，第 i 条线的两个端点是 (i, 0) 和 (i, height[i]) 。

找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。

返回容器可以储存的最大水量。

说明：你不能倾斜容器。
 */
int maxArea(std::vector<int> &height);

/*
给你一个整数数组 nums ，判断是否存在三元组 [nums[i], nums[j], nums[k]] 满足 i != j、i != k 且 j != k ，同时还满足 nums[i] + nums[j] + nums[k] == 0 。请你返回所有和为 0 且不重复的三元组。

注意：答案中不可以包含重复的三元组。
*/
std::vector<std::vector<int>> threeSum(std::vector<int>& nums);


#endif // __ALGORITHM_H__