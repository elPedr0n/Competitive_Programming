for t in range(int(input())):
    led = [6, 2, 5, 5, 4, 5, 6, 3, 7, 6]
    total = 0
    for letter in input():
        total += led[int(letter)]
    print(str(total) + " leds")