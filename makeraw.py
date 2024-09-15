from __future__ import annotations

def makeraw(file_path: str) -> None:
    with open(file_path, 'r') as f_Io_r:
        f_string: str = f_Io_r.read()
        n_string_content = f_string.replace('\n', '').replace('\t', '').replace('  ', '')
        print(n_string_content, sep='', end='\n')

if __name__ == "__main__": 
    makeraw('pages\\index.html')
    