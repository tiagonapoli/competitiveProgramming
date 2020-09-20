filetype indent on
filetype indent on
set scrolloff=10
set smarttab
colorscheme desert
set noswapfile
set t_Co=256

syntax enable
set autoindent
set smartindent

set tabstop=4
set shiftwidth=4
set expandtab
set number
set mouse=a

set cindent

au BufNewFile *.cpp 0r ~/Documents/competitiveProgramming/template.cpp

set ai si noet ts=4 sw=4 sta sm nu rnu
inoremap {<CR> {<CR>}<Esc>O
inoremap <NL> <ESC>o
nnoremap <NL> o
inoremap <C-up> <C-o>:m-2<CR>
inoremap <C-down> <C-o>:m+1<CR>
nnoremap <C-up> :m-2<CR>
nnoremap <C-down> :m+1<CR>
vnoremap <C-up> :m-2<CR>gv
vnoremap <C-down> :m'>+1<CR>gv

