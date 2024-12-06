def get_mul(s: str):
    found = s.find("mul(")
    if found == -1:
        return -1, -1, -1
    first_num_index = found + 4
    
    comma_index = s.find(",", first_num_index)

    if comma_index == -1:
        return -1, -1, -1
    
    # get the first num
    try:
        first_num = int(s[first_num_index:comma_index])
    except:
        return -1, -1, -1 
    
    end_paren_index = s.find(")", comma_index)

    if end_paren_index == -1:
        return -1, -1, -1

    # get the second num
    try:
        second_num = int(s[comma_index + 1:end_paren_index])
    except:
        return -1, -1, -1

    return first_num * second_num, found, end_paren_index
        


        

def main():
    with open("input.txt", "r") as input_file:
        lines = input_file.readlines()

        res = 0

        for line in lines:
           i = 0

           while (i < len(line) - 6 and len(line) > 6):
            mult, begin_index, end_index = get_mul(line[i::])

            if mult == -1:

                i += 1
            else:
                res += mult

                # remove the begin index and end index
                #print(line[begin_index:end_index + 1])
                line = line[i:begin_index] + line[end_index + 1::]

        print(res)
         
        

if __name__ == "__main__":
    main()