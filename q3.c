def reverse_array():
    n = int(input())
    arr = list(map(int, input().split()))

    left = 0
    right = n - 1
    
    while left < right:
        arr[left], arr[right] = arr[right], arr[left]
        left += 1
        right -= 1
    
    print(*(arr))

if __name__ == "__main__":
    reverse_array()
