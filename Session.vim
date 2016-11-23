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
badd +62 src/lib_ls_long2.c
badd +37 src/ft_ls_long.c
badd +82 includes/ft_ls.h
badd +60 ~/.tmux.conf
badd +35 src/lib_ls_long.c
badd +29 src/lib_lsdata.c
badd +39 src/lib_parse.c
badd +22 libft/src/ft_printf/lib_pad.c
badd +19 libft/src/ft_printf/lib_pad_sharp.c
badd +14 libft/src/lst/ft_lst_filter.c
badd +14 src/lib_dirents.c
badd +21 src/main.c
badd +42 src/ft_ls.c
badd +23 src/ft_ent_free.c
badd +17 Makefile
badd +38 src/lib_error.c
badd +32 src/lib_dirs.c
badd +36 src/ft_dir_get_ents.c
badd +69 libft/src/ft_printf/ft_printf.c
badd +46 libft/includes/ft_printf.h
badd +2 libft/src/printing/ft_putstr_fd.c
badd +112 libft/includes/libft.h
badd +2 libft/src/ft_printf/lib_fmt.c
badd +1 src/.lib_dirents.c.swo
badd +1 ft_ls
badd +1 libft/src/dlst/ft_dlstdel.c
badd +20 libft/src/lst/ft_lstdel.c
badd +21 libft/src/path/ft_path_notdir.c
badd +1 libft/src/mem/ft_memcpy.c
badd +19 libft/src/mem/ft_memdel.c
badd +32 libft/src/lst/ft_lst_delif.c
badd +22 libft/src/lst/ft_lstdelone.c
badd +25 libft/src/lst/ft_lst_removeif.c
badd +1 ~/.vimrc
badd +24 src/ft_ent_has_dir.c
badd +35 src/ft_ent_get_dirs.c
badd +36 src/lib_ent.c
badd +11 .Makefile.swp
badd +29 ~/dotfiles/vim.symlink/plugins.vim
badd +22 libft/src/str/ft_strsub.c
badd +1 libft/Makefile
badd +14 libft/src/btree/btree_print.c
badd +14 libft/src/printing/ft_putaddr.c
badd +13 libft/src/str/ft_strinsert.c
badd +20 libft/src/str/ft_strdel.c
badd +22 libft/src/str/ft_strjoin.c
badd +0 libft/src/mem/ft_memset.c
badd +35 libft/includes/lst.h
badd +15 libft/src/sstr/ft_sstrsort.c
badd +25 libft/src/lst/ft_lstsort.c
badd +20 libft/src/lst/ft_lst_sort.c
badd +5 ~/dotfiles/vim.symlink/aliases.vim
badd +0 lol
badd +18 src/ft_ls_short.c
badd +30 src/lib_time.c
args src/lib_ls_long2.c
edit includes/ft_ls.h
set splitbelow splitright
wincmd _ | wincmd |
vsplit
1wincmd h
wincmd w
set nosplitbelow
set nosplitright
wincmd t
set winheight=1 winwidth=1
exe 'vert 1resize ' . ((&columns * 90 + 102) / 204)
exe 'vert 2resize ' . ((&columns * 113 + 102) / 204)
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
let s:l = 28 - ((27 * winheight(0) + 40) / 80)
if s:l < 1 | let s:l = 1 | endif
exe s:l
normal! zt
28
normal! 025l
wincmd w
argglobal
edit src/main.c
setlocal fdm=manual
setlocal fde=0
setlocal fmr={{{,}}}
setlocal fdi=#
setlocal fdl=0
setlocal fml=1
setlocal fdn=20
setlocal fen
silent! normal! zE
let s:l = 25 - ((24 * winheight(0) + 40) / 80)
if s:l < 1 | let s:l = 1 | endif
exe s:l
normal! zt
25
normal! 01l
wincmd w
exe 'vert 1resize ' . ((&columns * 90 + 102) / 204)
exe 'vert 2resize ' . ((&columns * 113 + 102) / 204)
tabedit src/lib_parse.c
set splitbelow splitright
set nosplitbelow
set nosplitright
wincmd t
set winheight=1 winwidth=1
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
let s:l = 80 - ((55 * winheight(0) + 40) / 80)
if s:l < 1 | let s:l = 1 | endif
exe s:l
normal! zt
80
normal! 02l
tabedit src/lib_time.c
set splitbelow splitright
set nosplitbelow
set nosplitright
wincmd t
set winheight=1 winwidth=1
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
let s:l = 29 - ((28 * winheight(0) + 40) / 80)
if s:l < 1 | let s:l = 1 | endif
exe s:l
normal! zt
29
normal! 0
tabedit src/ft_ls.c
set splitbelow splitright
wincmd _ | wincmd |
vsplit
1wincmd h
wincmd w
set nosplitbelow
set nosplitright
wincmd t
set winheight=1 winwidth=1
exe 'vert 1resize ' . ((&columns * 102 + 102) / 204)
exe 'vert 2resize ' . ((&columns * 101 + 102) / 204)
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
let s:l = 24 - ((23 * winheight(0) + 40) / 80)
if s:l < 1 | let s:l = 1 | endif
exe s:l
normal! zt
24
normal! 08l
wincmd w
argglobal
edit src/lib_ls_long.c
setlocal fdm=manual
setlocal fde=0
setlocal fmr={{{,}}}
setlocal fdi=#
setlocal fdl=0
setlocal fml=1
setlocal fdn=20
setlocal fen
silent! normal! zE
let s:l = 38 - ((36 * winheight(0) + 40) / 80)
if s:l < 1 | let s:l = 1 | endif
exe s:l
normal! zt
38
normal! 03l
wincmd w
exe 'vert 1resize ' . ((&columns * 102 + 102) / 204)
exe 'vert 2resize ' . ((&columns * 101 + 102) / 204)
tabedit src/lib_ent.c
set splitbelow splitright
set nosplitbelow
set nosplitright
wincmd t
set winheight=1 winwidth=1
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
let s:l = 32 - ((31 * winheight(0) + 40) / 80)
if s:l < 1 | let s:l = 1 | endif
exe s:l
normal! zt
32
normal! 019l
tabnext 5
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
