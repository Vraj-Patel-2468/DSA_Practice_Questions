def search(nums: list[int], target: int) -> int:
    if not nums:
        return -1  
    size = len(nums)
    L, R = 0, size - 1
    while L <= R:
        mid = L+(R-L)//2
        if nums[mid] == target:
            return mid
        if nums[L]<=nums[mid]:
            if nums[L] <= target <= nums[mid]:
                R = mid - 1
            else:
                L = mid + 1
        else:
            if nums[mid] <= target <= nums[R]:
                L = mid + 1
            else:
                R = mid - 1        
    return -1
 
        

def main():
    nums = [15, 18, 2, 3, 6, 12]
    target = 12
    ans = search(nums, target)
    print(ans)

if __name__ == "__main__":
    main()
    