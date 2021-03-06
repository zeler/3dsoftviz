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

#include <sys/time.h>
#include <sys/resource.h>

float timer ()
{
  struct rusage r;

  getrusage(0, &r);
  return (float)(r.ru_utime.tv_sec+r.ru_utime.tv_usec/(float)1000000);
}

int main() {
  
  igraph_t g;
  igraph_real_t flow;
  igraph_vector_t capacity;
  long int i;
  igraph_integer_t source, target;
  FILE *infile;
  float t;

  igraph_vector_init(&capacity, 0);

  /***************/
  infile=fopen("ak-4102.max", "r");
  igraph_read_graph_dimacs(&g, infile, 0, 0, &source, &target, &capacity,
			   IGRAPH_DIRECTED);
  fclose(infile);

  t=timer();
  igraph_maxflow_value(&g, &flow, source, target, &capacity);
  t=timer()-t;
/*   printf("4102: %g (time %.10f)\n", flow, t); */
  if (flow != 8207) {
    return 1;
  }
  igraph_destroy(&g);  
  /***************/

/*   /\***************\/ */
/*   infile=fopen("ak-8198.max", "r"); */
/*   igraph_read_graph_dimacs(&g, infile, 0, 0, &source, &target, &capacity, */
/* 			   IGRAPH_DIRECTED); */
/*   fclose(infile); */

/*   t=timer(); */
/*   igraph_maxflow_value(&g, &flow, source, target, &capacity); */
/*   t=timer()-t; */
/*   printf("8198: %g (time %.10f)\n", flow, t); */
/*   igraph_destroy(&g); */
/*   /\***************\/ */

/*   /\***************\/ */
/*   infile=fopen("ak-16390.max", "r"); */
/*   igraph_read_graph_dimacs(&g, infile, 0, 0, &source, &target, &capacity, */
/* 			   IGRAPH_DIRECTED); */
/*   fclose(infile); */

/*   t=timer(); */
/*   igraph_maxflow_value(&g, &flow, source, target, &capacity); */
/*   t=timer()-t; */
/*   printf("16390: %g (time %.10f)\n", flow, t); */
/*   igraph_destroy(&g); */
/*   /\***************\/ */

/*   /\***************\/ */
/*   infile=fopen("ak-32774.max", "r"); */
/*   igraph_read_graph_dimacs(&g, infile, 0, 0, &source, &target, &capacity, */
/* 			   IGRAPH_DIRECTED); */
/*   fclose(infile); */

/*   t=timer(); */
/*   igraph_maxflow_value(&g, &flow, source, target, &capacity); */
/*   t=timer()-t; */
/*   printf("32774: %g (time %.10f)\n", flow, t); */
/*   igraph_destroy(&g); */
/*   /\***************\/ */

/*   /\***************\/ */
/*   infile=fopen("ak-65542.max", "r"); */
/*   igraph_read_graph_dimacs(&g, infile, 0, 0, &source, &target, &capacity, */
/* 			   IGRAPH_DIRECTED); */
/*   fclose(infile); */

/*   t=timer(); */
/*   igraph_maxflow_value(&g, &flow, source, target, &capacity); */
/*   t=timer()-t; */
/*   printf("65542: %g (time %.10f)\n", flow, t); */
/*   igraph_destroy(&g); */
/*   /\***************\/ */

  igraph_vector_destroy(&capacity);
  
  return 0;
}
