n = int(input())

dict = [
    ['I', 'II', 'III', 'IV', 'V', 'VI', 'VII', 'VIII', 'IX'],
    ['X', 'XX', 'XXX', 'XL', 'L', 'LX', 'LXX', 'LXXX', 'XC'],
    ['C', 'CC', 'CCC', 'CD', 'D', 'DC', 'DCC', 'DCCC', 'CM'],
    ['M', 'MM', 'MMM'],
]

rank = 0
res = ''
while n > 0:
    last_digit = n % 10

    if last_digit > 0:
        roman = dict[rank][last_digit - 1]
        res = roman + res

    n //= 10
    rank += 1

print(res)