/*
 * OCamlSDL - An ML interface to the SDL library
 * Copyright (C) 1999  Frederic Brunel
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

/* $Id: common.c,v 1.1 2001/04/24 19:39:28 xtrm Exp $ */


#include <caml/mlvalues.h>
#include <caml/memory.h>
#include <caml/alloc.h>
/*  #include <caml/fail.h>
 *  #include <caml/callback.h> */

/*

  Caml list manipulations

  Grabbed in ocamlsdl-0.3/sdl_stub.c 1.8 (2000/09/25)
  made by Jean-Christophe FILLIATRE 
*/

#include "common.h"


#define NIL_tag 0
#define CONS_tag 1

value nil(void)
{
  return Val_int(0);
}

value cons(value x,value l)
{
  CAMLparam2(x,l);
  CAMLlocal1(m);
  m=alloc(2,CONS_tag);
  Store_field(m,0,x);
  Store_field(m,1,l);
  CAMLreturn (m);
}

int is_nil(value l)
{
  return Is_long(l);
}

int is_not_nil(value l)
{
  return Is_block(l);
}

value hd(value l)
{
  return Field(l,0);
}

value tl(value l)
{
  return Field(l,1);
}