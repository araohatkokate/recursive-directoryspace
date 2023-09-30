# Name - Araohat Kokate
# Net ID - 1001829841
# Language version - Python 3.10.6
# OS used - Windows 11
import os

#recursive function to calculate size
def calculate_total_size(directory):
    total_size = 0 #variable to store size of files in bytes
    for item in os.listdir(directory):
        item_path = os.path.join(directory, item)
        if os.path.isfile(item_path):
            total_size += os.path.getsize(item_path)
        elif os.path.isdir(item_path) and item not in ('.', '..'):
            total_size += calculate_total_size(item_path)
    return total_size

def main():
    current_directory = os.getcwd()
    total_size = calculate_total_size(current_directory)
    
    print(f"Total size : {total_size} bytes")

if __name__ == "__main__":
    main()
