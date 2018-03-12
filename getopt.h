/*
 * getotp.h
 *
 *  Created on: 9 Mar 2018
 *      Author: toannm
 */

#ifndef GETOPT_H_
#define GETOPT_H_

extern char *optarg;
extern int optind;

int getopt(int nargc, char * const nargv[], const char *ostr) ;




#endif /* GETOPT_H_ */
