def problem7():
    nums1 = input()
    nums2 = input()
    index = 0
    for pro in nums1:
        if pro == nums2[index]:
            print(1, end='')
        else:
            print(0, end='')
        index = index + 1


if __name__ == '__main__':
    problem7()
