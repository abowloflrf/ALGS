def problem6():
    number = int(input())
    while number != -1:
        total = {}
        total_v = 0
        for person in range(0, number):
            detail = input().strip().split(' ')
            total[detail[3]] = int(detail[0]) * int(detail[1]) * int(detail[2])
            total_v += total[detail[3]]
        avg_v = total_v / number
        persons = []
        for person in total:
            if total[person] != avg_v:
                persons.append(person)
        if total[persons[0]] > total[persons[1]]:
            print(persons[0]+" took clay from "+persons[1]+'.')
        else:
            print(persons[1]+" took clay from "+persons[0]+'.')
        number = int(input())


if __name__ == '__main__':
    problem6()
