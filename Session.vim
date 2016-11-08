let SessionLoad = 1
if &cp | set nocp | endif
let s:so_save = &so | let s:siso_save = &siso | set so=0 siso=0
let v:this_session=expand("<sfile>:p")
silent only
cd ~/ft_ls
if expand('%') == '' && !&modified && line('$') <= 1 && getline(1) == ''
  let s:wipebuf = bufnr('%')
endif
set shortmess=aoO
badd +103 src/lib_ls_long2.c
badd +27 src/ft_ls_long.c
badd +45 includes/ft_ls.h
badd +60 ~/.tmux.conf
badd +47 src/lib_ls_long.c
badd +35 src/lib_lsdata.c
badd +59 src/lib_parse.c
badd +22 libft/src/ft_printf/lib_pad.c
badd +19 libft/src/ft_printf/lib_pad_sharp.c
badd +9 libft/src/lst/ft_lst_filter.c
badd +30 src/lib_dirents.c
badd +26 src/main.c
badd +32 src/ft_ls.c
badd +23 src/ft_ent_free.c
badd +1 Makefile
badd +14 src/lib_error.c
badd +32 src/lib_dirs.c
badd +29 src/ft_dir_get_ents.c
args src/lib_ls_long2.c
edit src/main.c
set splitbelow splitright
wincmd _ | wincmd |
vsplit
1wincmd h
wincmd w
set nosplitbelow
set nosplitright
wincmd t
set winheight=1 winwidth=1
exe 'vert 1resize ' . ((&columns * 105 + 102) / 205)
exe 'vert 2resize ' . ((&columns * 99 + 102) / 205)
argglobal
setlocal fdm=manual
setlocal fde=0
setlocal fmr={{{,}}}
setlocal fdi=#
setlocal fdl=0
setlocal fml=1
setlocal fdn=20
setlocal fen
silent! normal! zE
let s:l = 25 - ((24 * winheight(0) + 37) / 75)
if s:l < 1 | let s:l = 1 | endif
exe s:l
normal! zt
25
normal! 01l
wincmd w
argglobal
edit includes/ft_ls.h
setlocal fdm=manual
setlocal fde=0
setlocal fmr={{{,}}}
setlocal fdi=#
setlocal fdl=0
setlocal fml=1
setlocal fdn=20
setlocal fen
silent! normal! zE
let s:l = 24 - ((23 * winheight(0) + 37) / 75)
if s:l < 1 | let s:l = 1 | endif
exe s:l
normal! zt
24
normal! 0
wincmd w
exe 'vert 1resize ' . ((&columns * 105 + 102) / 205)
exe 'vert 2resize ' . ((&columns * 99 + 102) / 205)
tabedit src/lib_parse.c
set splitbelow splitright
wincmd _ | wincmd |
vsplit
1wincmd h
wincmd w
set nosplitbelow
set nosplitright
wincmd t
set winheight=1 winwidth=1
exe 'vert 1resize ' . ((&columns * 105 + 102) / 205)
exe 'vert 2resize ' . ((&columns * 99 + 102) / 205)
argglobal
setlocal fdm=manual
setlocal fde=0
setlocal fmr={{{,}}}
setlocal fdi=#
setlocal fdl=0
setlocal fml=1
setlocal fdn=20
setlocal fen
silent! normal! zE
let s:l = 41 - ((32 * winheight(0) + 37) / 75)
if s:l < 1 | let s:l = 1 | endif
exe s:l
normal! zt
41
normal! 0
wincmd w
argglobal
edit src/lib_ls_long2.c
setlocal fdm=manual
setlocal fde=0
setlocal fmr={{{,}}}
setlocal fdi=#
setlocal fdl=0
setlocal fml=1
setlocal fdn=20
setlocal fen
silent! normal! zE
let s:l = 68 - ((37 * winheight(0) + 37) / 75)
if s:l < 1 | let s:l = 1 | endif
exe s:l
normal! zt
68
normal! 03l
wincmd w
exe 'vert 1resize ' . ((&columns * 105 + 102) / 205)
exe 'vert 2resize ' . ((&columns * 99 + 102) / 205)
tabnext 1
if exists('s:wipebuf')
  silent exe 'bwipe ' . s:wipebuf
endif
unlet! s:wipebuf
set winheight=1 winwidth=20 shortmess=filnxtToO
let s:sx = expand("<sfile>:p:r")."x.vim"
if file_readable(s:sx)
  exe "source " . fnameescape(s:sx)
endif
let &so = s:so_save | let &siso = s:siso_save
let g:this_session = v:this_session
let g:this_obsession = v:this_session
let g:this_obsession_status = 2
doautoall SessionLoadPost
unlet SessionLoad
" vim: set ft=vim :
