from collections import defaultdict

def main():
    with open("input.txt", "r") as input:
        # there are two numbers in each line
        lines = input.readlines()

        list1 = []
        list2 = []

        for line in lines:
            line_split = line.split(" ")

            num1 = int(line_split[0])
            num2 = int(line_split[-1])

            list1.append(num1)
            list2.append(num2)

        list1.sort()
        list2.sort()

        res = 0

        for i in range(len(list1)):
            print(list1[i], list2[i])
            res += abs(list1[i] - list2[i])
        
        # part 1
        print(res)

        # part 2
        hash1 = defaultdict(lambda: 0)
        hash2 = defaultdict(lambda: 0)

        for i in list1:
            hash1[i] += 1

        for i in list2:
            hash2[i] += 1

        similarity_score = 0

        for i in list1:
            similarity_score += hash2[i] * i

        print(f"Similarity score: {similarity_score}")

        return res

            

if __name__ == "__main__":
    main()