set nocompatible
filetype on
filetype indent on
filetype plugin on
set fileencodings=utf-8,ucs-bom,gb18030,gbk,gb2312,cp936
set termencoding=utf-8
set encoding=utf-8

syntax on
au BufNewFile,BufRead *.f08 set filetype=fortran


set number
set norelativenumber
set cursorline
set wrap
set wildmenu
set showcmd
set incsearch
set smartcase
set ignorecase
set hlsearch

set nocompatible              " be iMproved, required
filetype off                  " required

set nocompatible              "去掉有关vi一致性模式，避免以前版本的bug和局限    
filetype on                   "检测文件的类型     
set autoindent                "vim使用自动对齐，也就是把当前行的对齐格式应用到下一行(自动缩进）
set cindent                   "（cindent是特别针对 C语言语法自动缩进）
set smartindent               "依据上面的对齐格式，智能的选择对齐方式，对于类似C语言编写上有用   
set tabstop=4                 "设置tab键为4个空格，
set shiftwidth =4             "设置当行之间交错时使用4个空格     
set ai!                       " 设置自动缩进 
set showmatch      "设置匹配模式，类似当输入一个左括号时会匹配相应的右括号      
set guioptions-=T             "去除vim的GUI版本中得toolbar   
set vb t_vb=                  "当vim进行编辑时，如果命令错误，会发出警报，该设置去掉警报       
set ruler                     "在编辑过程中，在右下角显示光标位置的状态行     
set nohls                     "默认情况下，寻找匹配是高亮度显示，该设置关闭高亮显示     
set incsearch                 "在程序中查询一单词，自动匹配单词的位置；如查询desk单词，当输到/d时，会自动找到第一个d开头的单词，当输入到/de时，会自动找到第一个以ds开头的单词，以此类推，进行查找；当找到要匹配的单词时，别忘记回车 
"set expandtab
set tabstop=2
"set shiftwidth=2
"set softtabstop=2
"set list
"set scrolloff=5



map sl :set splitright<CR>:vsplit<CR>
map sh :set nosplitright<CR>:vsplit<CR>
map sk :set nosplitbelow<CR>:split<CR>
map sj :set splitbelow<CR>:split<CR>

map tn :tabe<CR>
map th :+tabnext<CR>
map tl :-tabnext<CR>

map S :w<CR>
map Q :q<CR>
map R :source $MYVIMRC<CR>
map T :bo term<CR>



map <LEADER>l <C-w>l
map <LEADER>k <C-w>k
map <LEADER>h <C-w>h
map <LEADER>j <C-w>j


"map <up> :res +5<CR>
"map <down> :res -5<CR>
map <left> :vertical resize+5<CR>
map <right> :vertical resize-5<CR>


map sv <C-w>t<C-w>H
map sh <C-w>t<C-w>K


noremap = nzz
noremap - Nzz
noremap J 5j
noremap K 5k


map r :MarkdownPreview<CR>


"fortran语言制表符设置
let fortran_have_tabs=1
"设置代码折叠
let fortran_fold=1
set foldmethod=syntax
"设置默认文件打开后所有折叠自动展开
set foldlevelstart=99

inoremap ' ''<ESC>i
inoremap " ""<ESC>i
inoremap ( ()<ESC>i
inoremap [ []<ESC>i
inoremap { {}<ESC>i

call plug#begin('~/.vim/plugged')
" alternatively, pass a path where Vundle should install plugins
" Make sure you use single quotes
Plug 'vim-airline/vim-airline'
Plug 'connorholyday/vim-snazzy'
Plug 'lervag/vimtex'
"Plug 'vim-latex/vim-latex'
"Plug 'jcf/vim-latex'
"Plug 'KeitaNakamura/tex-conceal.vim', {'for': 'tex'}
"Plug 'wjakob/wjakob.vim'
Plug 'rudrab/vimf90'
" A Vim Plugin for Lively Previewing LaTeX PDF Output
"Plug 'xuhdev/vim-latex-live-preview', { 'for': 'tex' }
" 文件树
"Plug 'scrooloose/nerdtree'

"Plug 'ryanoasis/vim-devicons'
" 文件数图标
" 代码格式化美化
"Plug 'Chiel92/vim-autoformat'
" vim配色方案
"Plug 'flazz/vim-colorschemes'
" 通用代码注释
"Plug 'tpope/vim-commentary'
" usage
" gcc 注释所在行
" gc 注释选中部分 visual模式下
" gcu 撤销上一次注释
" gcgc 撤销注释当前行和临近的N行注释
"Plug 'junegunn/vim-easy-align'
" usage
" ea进入对齐模式
" 默认是左对齐
" 回车进入R模式是右对齐 right
" 再次回车进入C模式是居中对齐 Centered
" 紧接着输入对齐中间的字符，也就是分隔符
" 补全插件
Plug 'ycm-core/YouCompleteMe', { 'do': 'python3 install.py --clangd-completer'}
" bash插件 在vim中运行command
Plug 'tpope/vim-pathogen'
" 符号编辑插件
"Plug 'tpope/vim-surround'
" git管理器
"Plug 'tpope/vim-fugitive'
" c++ stl高亮
"Plug 'octol/vim-cpp-enhanced-highlight'
" tab自动补全内容
Plug 'SirVer/ultisnips'
Plug 'honza/vim-snippets'
" 对称括号加颜色
" Plug 'frazrepo/vim-rainbow'


" Shorthand notation; fetches https://github.com/junegunn/vim-easy-align
"Plug 'junegunn/vim-easy-align'

" Any valid git URL is allowed
Plug 'https://github.com/junegunn/vim-github-dashboard.git'

" Multiple Plug commands can be written in a single line using | separators

" On-demand loading
Plug 'scrooloose/nerdtree', { 'on':  'NERDTreeToggle' }
Plug 'tpope/vim-fireplace', { 'for': 'clojure' }

" Using a non-default branch
"Plug 'rdnetto/YCM-Generator', { 'branch': 'stable' }

" Using a tagged release; wildcard allowed (requires git 1.9.2 or above)
"Plug 'fatih/vim-go', { 'tag': '*' }

" Plugin options
"Plug 'nsf/gocode', { 'tag': 'v.20150303', 'rtp': 'vim' }

" Plugin outside ~/.vim/plugged with post-update hook
"Plug 'junegunn/fzf', { 'dir': '~/.fzf', 'do': './install --all' }

" Unmanaged plugin (manually installed and updated)
Plug '~/my-prototype-plugin'
"Plug 'iamcco/mathjax-support-for-mkdp'
"Plug 'iamcco/markdown-preview.vim'
Plug 'iamcco/markdown-preview.nvim',{ 'do': { -> mkdp#util#install_sync() }, 'for' :['markdown', 'vim-plug'] }

Plug 'vimwiki/vimwiki'

Plug 'yinflying/matlab.vim'

call plug#end()

let g:SnazzyTransparent = 1

" 设置youcompleteme
let g:ycm_autoclose_preview_window_after_completion=0
let g:ycm_autoclose_preview_window_after_insertion=1
let g:ycm_use_clangd = 0
let g:ycm_python_interpreter_path="/home/lenovo/Soft/anaconda3/bin/python3"
let g:ycm_python_binary_path = "/home/lenovo/Soft/anaconda3/bin/python3"
let g:ycm_global_ycm_extra_conf='~/.ycm_extra_conf.py'
let g:ycm_global_ycm_extra_conf='~/.vim/plugged/YouCompleteMe/third_party/ycmd/.ycm_extra_conf.py'
let g:ycm_confirm_extra_conf = 0
let g:ycm_semantic_triggers = {
      \ 'c,fortran,cpp,latex,matlab,python,java,go,erlang,perl': ['re!\w{2}'],
      \ 'cs,lua,javascript': ['re!\w{2}'],
      \ }

" 不在单独打开窗口显示函数原型
set completeopt=menu,menuone
let g:ycm_add_preview_to_completeopt = 0
let g:ycm_show_diagnostics_ui = 0
" ycm显示补全的白名单 1==True
let g:ycm_filetype_whitelist = {
      \ "c":1,
      \ "cpp":1,
      \ "objc":1,
      \ "sh":1,
      \ "zsh":1,
      \ "zimbu":1,
      \ "python":1,
      \ "vim":1,
      \ "text":1,
      \ "tex":1,
      \ "matlab":1,
      \"fortran":1,
      \ }
" 设置octol/vim-cpp-enhanced-highlight
" 默认不高亮类作用域
let g:cpp_class_scope_highlight = 1
" 成员变量也是默认不显示
let g:cpp_member_variable_highlight = 1
" 声明中高亮类名
let g:cpp_class_decl_highlight = 1
" 模版突出显示
let g:cpp_experimental_template_highlight = 1
" 库突出显示
let g:cpp_concepts_highlight = 1

" 设置ultisnips
let g:UltiSnipsExpandTrigger="<tab>"

" 高亮显示当前行和列




" IMPORTANT: grep will sometimes skip displaying the file name if you
" search in a singe file. This will confuse Latex-Suite. Set your grep
" program to always generate a file-name.
set grepprg=grep\ -nH\ $*


" ===
" === MarkdownPreview
" ===
let g:mkdp_auto_start = 0
let g:mkdp_auto_close = 1
let g:mkdp_refresh_slow = 0
let g:mkdp_command_for_global = 0
let g:mkdp_open_to_the_world = 0
let g:mkdp_open_ip = ''
let g:mkdp_browser = 'google-chrome'
let g:mkdp_echo_preview_url = 0
let g:mkdp_browserfunc = ''
let g:mkdp_preview_options = {
    \ 'mkit': {},
    \ 'katex': {},
    \ 'uml': {},
    \ 'maid': {},
    \ 'disable_sync_scroll': 0,
    \ 'sync_scroll_type': 'middle',
    \ 'hide_yaml_meta': 1
    \ }
let g:mkdp_markdown_css = ''
let g:mkdp_highlight_css = ''
let g:mkdp_port = ''
let g:mkdp_page_title = '「${name}」'




let python_highlight_all=1
au Filetype python set tabstop=4
au Filetype python set softtabstop=4
au Filetype python set shiftwidth=4
au Filetype python set textwidth=79
au Filetype python set expandtab
au Filetype python set autoindent
au Filetype python set fileformat=unix
autocmd Filetype python set foldmethod=indent
autocmd Filetype python set foldlevel=99
map <F5> :call RunPython()<CR>
func! RunPython()
        exec "W"
        if &filetype == 'c'
                exec "!g++ % -o %<"
                exec "!time ./%<"
        elseif &filetype == 'cpp'
                exec "!g++ % -o %<"
                exec "!time ./%<"
        elseif &filetype == 'java'
                exec "!javac %"
                exec "!time java %<"
        elseif &filetype == 'sh'
                :!time bash %
        elseif &filetype == 'python'
                exec "!clear"
                exec "!time python3 %"
        elseif &filetype == 'html'
                exec "!firefox % &"
        elseif &filetype == 'go'
                " exec "!go build %<"
                exec "!time go run %"
        elseif &filetype == 'mkd'
                exec "!~/.vim/markdown.pl % > %.html &"
                exec "!firefox %.html &"
        elseif &filetype =='fortran'
               exec	"!gfortran  %"		
               exec "!time ./a.out"
        endif
endfunc

map <F12> :VimtexCompile<CR>

"let g:Tex_ViewRule_pdf = 'evince'
let g:tex_flavor='latex'
set iskeyword+=:
let g:Tex_CompileRule_pdf='xelatex -interaction=nonstopmode $*'
let g:Tex_DefaultTargetFormat="pdf"
let g:vimtex_view_method='general'
let g:vimtex_compiler_latexmk = {
	\ 'build_dir' : '',
    \ 'callback' : 1,
    \ 'continuous' : 1,
    \ 'executable' : 'latexmk',
    \ 'hooks' : [],
    \ 'options' : [
    \   '-verbose',
    \   '-file-line-error',
    \   '-synctex=1',
    \   '-interaction=nonstopmode',
    \ ],
    \}
let g:vimtex_compiler_latexmk_engines = {
 \ '_'                : '-xelatex',
        \ 'pdflatex'         : '-pdf',
        \ 'dvipdfex'         : '-pdfdvi',
        \ 'lualatex'         : '-lualatex',
        \ 'xelatex'          : '-xelatex',
        \ 'context (pdftex)' : '-pdf -pdflatex=texexec',
        \ 'context (luatex)' : '-pdf -pdflatex=context',
        \ 'context (xetex)'  : '-pdf -pdflatex=''texexec --xtx''',
    \}


let g:vimwiki_list = [{'path': '~/vimwiki/',
                      \ 'syntax': 'markdown', 'ext': '.md'}]


"matlab插件的配置
let g:syntastic_matlab_mlint_option='-config=[setting.txt] -id'
autocmd BufEnter *.m    compiler mlint
source $VIMRUNTIME/macros/matchit.vim
au FileType matlab map <buffer> <silent> <F5> :w<CR>:!matlab -nodesktop -nosplash -r "try, run(which('%')), end, quit" <CR><CR>
au FileType matlab set foldmethod=syntax foldcolumn=2 foldlevel=33
