def is_correct_brackets(text, bracket_start, bracket_end):
    counter = 0
    for c in text:
        if c == bracket_start:
            counter += 1
        elif c == bracket_end:
            counter -= 1
        if counter < 0:
            return False
    return counter == 0

txt = input()

print(is_correct_brackets(txt, '(', ')') and is_correct_brackets(txt, '[', ']') and is_correct_brackets(txt, '{', '}'))