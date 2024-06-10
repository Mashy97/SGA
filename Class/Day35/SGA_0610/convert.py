import csv
import os

def add_row_names(input_csv, output_csv):
    with open(input_csv, 'r', encoding='utf-8') as infile, open(output_csv, 'w', encoding='utf-8', newline='') as outfile:
        reader = csv.reader(infile)
        writer = csv.writer(outfile)

        # Read header
        header = next(reader)
        header.insert(0, 'Key')  # Add RowName to the header
        writer.writerow(header)

        # Read and modify each row
        for i, row in enumerate(reader):
            row.insert(0, f'Row{i+1}')  # Add row name
            writer.writerow(row)

# Example usage
input_csv = 'D:\\202406\\SGA_0610\\MusicBaseData_utf8.csv'
output_csv = 'D:\\202406\\SGA_0610\\MyStructDataWithRowNames.csv'
add_row_names(input_csv, output_csv)