def get_mul(s: str, starting_index):
    found = s.find("mul(", starting_index)
    
    if  found != starting_index:
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

        should_add = True

        res = 0

        for line in lines:
           i = 0

           while (i < len(line) and len(line)):
            # see if there's a do or don't statement

            if line[i:i+5] == "don't":
                i += 5
                should_add = False
            elif line[i:i+2] == "do":
                print("Past this point, multiply operations ARE possible")
                should_add = True
                i += 2

            mult, begin_index, end_index = get_mul(line, i)

            if mult == -1:
                i += 1
            else:
                
                if should_add:
                    print(line[begin_index:end_index + 1])
                    res += mult
                else:
                    print('cant do this one: ', line[begin_index:end_index + 1])

                # remove the begin index and end index
                #print(line[begin_index:end_index + 1])
                #line = line[i:begin_index] + line[end_index + 1::]

                i += 1

        print(res)
         
        

if __name__ == "__main__":
    main()