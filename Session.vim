let SessionLoad = 1
if &cp | set nocp | endif
let s:so_save = &so | let s:siso_save = &siso | set so=0 siso=0
let v:this_session=expand("<sfile>:p")
silent only
cd ~/
if expand('%') == '' && !&modified && line('$') <= 1 && getline(1) == ''
  let s:wipebuf = bufnr('%')
endif
set shortmess=aoO
badd +1 src/lib_ls_long2.c
badd +27 src/ft_ls_long.c
badd +25 includes/ft_ls.h
badd +60 ~/.tmux.conf
badd +52 src/lib_ls_long.c
badd +35 src/lib_lsdata.c
badd +76 src/lib_parse.c
badd +22 libft/src/ft_printf/lib_pad.c
badd +19 libft/src/ft_printf/lib_pad_sharp.c
badd +9 libft/src/lst/ft_lst_filter.c
badd +14 src/lib_dirents.c
badd +21 src/main.c
badd +30 src/ft_ls.c
badd +21 src/ft_ent_free.c
badd +1 Makefile
badd +16 src/lib_error.c
badd +32 src/lib_dirs.c
badd +31 src/ft_dir_get_ents.c
badd +33 libft/src/ft_printf/ft_printf.c
badd +43 libft/includes/ft_printf.h
badd +2 libft/src/printing/ft_putstr_fd.c
badd +11 libft/includes/libft.h
badd +2 libft/src/ft_printf/lib_fmt.c
badd +1 src/.lib_dirents.c.swo
badd +1 ft_ls
badd +1 libft/src/dlst/ft_dlstdel.c
badd +19 libft/src/lst/ft_lstdel.c
badd +21 libft/src/path/ft_path_notdir.c
badd +1 libft/src/mem/ft_memcpy.c
badd +19 libft/src/mem/ft_memdel.c
badd +31 libft/src/lst/ft_lst_delif.c
badd +22 libft/src/lst/ft_lstdelone.c
badd +25 libft/src/lst/ft_lst_removeif.c
badd +42 ~/.vimrc
badd +12 src/ft_ent_has_dir.c
badd +35 src/ft_ent_get_dirs.c
badd +19 src/lib_ent.c
badd +11 .Makefile.swp
badd +18 ~/dotfiles/vim.symlink/plugins.vim
badd +22 libft/src/str/ft_strsub.c
args src/lib_ls_long2.c
edit src/main.c
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
let s:l = 1 - ((0 * winheight(0) + 40) / 81)
if s:l < 1 | let s:l = 1 | endif
exe s:l
normal! zt
1
normal! 0
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
