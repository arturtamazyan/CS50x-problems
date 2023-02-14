import csv
import sys


def main():
    #first arguemnt should be a csv file,  e.g.
    #   name,AGATC,AATG,TATC
    #   Alice,2,8,3
    #   Bob,4,1,5
    #   Charlie,3,2,5
    database_file = open(sys.argv[1])
    database = csv.DictReader(database_file)


    #store csv data into a list e.g.
    people = []
    for person in database:
        people.append(person)

    #sequence is sequenns of [A, G, C, T] moleculs e.g. ...AAAAGGTGAGTTAAATAGAATAGGTTAAAATTAAAG...
    sequence_file = open(sys.argv[2])
    #save it just in string variable
    sequence = sequence_file.read()


    dict_of_strs = {}
    #there will be stored Short Tandem Repeats or STRs and their count in sequence e.g. ['AGAT':2, 'GTCAG':4, 'TCGCA':5]
    #we need this for accesing to 'people' list of dictionaries
    for person in people:
        for STR in person:
            #ignore names, right now we need only STRs
            if STR == "name":
                continue
            #and initial count is 0
            dict_of_strs[STR] = 0
        #STRs are in first row only, that's why after first iteration break the loop
        break

    #now assign longest matches of STRs in a given sequence into a dictionary
    #e.g. {"ATACG" : 13, "TTGCAT" : 9, ...}
    for str in dict_of_strs:
        dict_of_strs[str] = longest_match(sequence, str)


    strs_count_in_dict = len(dict_of_strs)
    for person in people:
        i = strs_count_in_dict
        for str in dict_of_strs:
            #all text in csv file is string, we should make it int
            if int(person[str]) != dict_of_strs[str]:
                #if count of person's 1 STR doesn's match with our data, no need to check for other STRs
                #this DNA does not belog to this person
                break
            #if we are there that means count of STRs matches, decrement 'i' by 1, maybe we will get to 0
            i -= 1
        #if 'i == 0', that means all STRs in our dict match with persons data, and this DNA belongs to person from this dict
        if i == 0:
            print(person["name"])
            #after founding person just exit the program
            sys.exit()

    if i != 0:
        print("No match")


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):
        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:
            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run


main()
