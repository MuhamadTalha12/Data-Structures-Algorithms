def is_operator(c):
    return c in ['+', '-', '*', '/', '(', ')']

def precedence(op):
    if op == '+' or op == '-':
        return 1
    if op == '*' or op == '/':
        return 2
    else:
        return 0

def inFixToPostfix(input):
    stack = []
    postFix = ''
    for char in input:
        if not is_operator(char):
            postfix += char
        elif char == '(':
            stack.append(char)
        elif char == ')':
            while stack and stack[-1] != '(':
                postfix += stack.pop()
            stack.pop()
        else:
            while stack and precedence(stack[-1]) >= precedence(char):
                postfix += stack.pop()
            stack.append(char)
    while stack:
        postfix += stack.pop()
    return postfix

if __name__ == "__main__":
    inFix_input = input("Enter infix input: ")
    postFix_input = inFixToPostfix(inFix_input)
    print("Postfix input:", postFix_input)