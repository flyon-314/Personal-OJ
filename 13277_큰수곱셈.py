import sys

def main():
    # 입력: 한 줄에 두 정수가 공백으로 구분되어 주어짐
    A, B = sys.stdin.readline().strip().split()
    # 정수로 변환하여 곱셈 수행
    result = int(A) * int(B)
    print(result)

if __name__ == '__main__':
    main()
