/* -*- mode: C -*-  */
/* 
   IGraph library.
   Copyright (C) 2006  Gabor Csardi <csardi@rmki.kfki.hu>
   MTA RMKI, Konkoly-Thege Miklos st. 29-33, Budapest 1121, Hungary
   
   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc.,  51 Franklin Street, Fifth Floor, Boston, MA 
   02110-1301 USA

*/

#include <igraph.h>
#include <stdlib.h>

extern int igraph_rng_inited;

int main() {

  igraph_t g1, g2;
  igraph_bool_t iso;

  srand(1122);
  igraph_rng_inited=1;
  
  igraph_erdos_renyi_game(&g1, IGRAPH_ERDOS_RENYI_GNP, 
			  100, 3.0/100, /*directed=*/ 0, /*loops=*/ 0);
  
  srand(1122);
  
  igraph_erdos_renyi_game(&g2, IGRAPH_ERDOS_RENYI_GNP, 
			  100, 3.0/100, /*directed=*/ 0, /*loops=*/ 0);

  igraph_isomorphic(&g1, &g2, &iso);
  
  if (!iso) {
    return 1;
  }

  igraph_destroy(&g2);
  igraph_destroy(&g1);
 
  return 0;
}
