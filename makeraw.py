from __future__ import annotations

from os import listdir, path

from dataclasses import dataclass

@dataclass
class _colors:
    succ = '\033[92m'; warn = '\033[93m'; fail = '\033[91m'
    endc = '\033[0m'; bold = '\033[1m'

if not path.exists('pages/'):
    print(f'{_colors.fail}{_colors.bold}`../pages/`{_colors.endc}{_colors.fail} path not found. exit -> 1\nfix -> create {_colors.fail}{_colors.bold}`../pages/`{_colors.fail}{_colors.endc} directory.'); exit(1)
    
def _mk_raw(path: str) -> str:
    with open(path, 'r') as f_Io_r:
        f_string: str = f_Io_r.read()
        n_string_content = f_string.replace('\n', '').replace('\t', '').replace('  ', '')
    with open(f'{path}.raw.html', 'w') as f_Io_w: f_Io_w.write(n_string_content)
    return n_string_content[:48]

if __name__ == "__main__":
    for fp in listdir("pages/"):
        if fp.endswith('.raw.html'): 
            print(f'{_colors.warn}please remove {_colors.bold}`pages/{fp}`{_colors.endc}{_colors.warn} file to proccess{_colors.endc}\n', sep='', end='')
            continue
        rs: str = _mk_raw(f'pages/{fp}')
        
        print(f'{_colors.succ}{_colors.bold}`{rs}...`{_colors.endc}{_colors.succ} succusfully proccesed{_colors.endc}\n', sep='', end='')
        print(f'{_colors.succ}{_colors.bold}`pages/`{fp}{_colors.endc}{_colors.succ} saved to {_colors.succ}{_colors.bold}`pages/{fp}.raw.html`{_colors.succ}{_colors.endc}\n', sep='', end='')
        