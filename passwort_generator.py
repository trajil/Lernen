import random
import os
import time

def input_password_length():
    print("Waiting for input...")
    length = int(input("Enter the length of your password: "))
    print(f"Length received: {length}")
    return length

def generate_password(length):
    password = ""
    for _ in range(length):
        random_char = chr(random.randint(33, 126))
        password += random_char
    return password

def main():
    start_time = time.time()  # Start timing
    #print("Starting program...")
    password_length = input_password_length()
    password = generate_password(password_length)

    os.makedirs('passwords', exist_ok=True)
    with open('passwords/passwordlist-py.txt', 'w') as file:
        file.write(password)

    end_time = time.time()  # End timing
    #print(f"Password generated: {password}")
    print(f"Execution time: {end_time - start_time} seconds")
    wait = input("")
if __name__ == "__main__":
    main()
