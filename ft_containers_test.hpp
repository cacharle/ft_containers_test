/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_containers_test.hpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charles <charles.cabergs@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/24 20:28:54 by charles           #+#    #+#             */
/*   Updated: 2020/04/25 10:39:15 by charles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CONTAINERS_TEST_HPP
# define FT_CONTAINERS_TEST_HPP

# include <iostream>
# include <string>

# include <cstdlib>
# include <unistd.h>
# include <sys/types.h>
# include <sys/wait.h>

# include "Vector.hpp"

static pid_t testSegvPid;

# define SANDBOX(x) do {             \
    testSegvPid = fork();            \
    if (testSegvPid == -1) abort();  \
    if (testSegvPid == 0) {          \
        do { (void)(x); } while(0);  \
        exit(EXIT_SUCCESS);          \
    }                                \
    wait(&testSegvPid);              \
} while(0)

# define ASSERT(x) do {                                                         \
    SANDBOX(x);                                                                 \
    if (!WIFEXITED(testSegvPid)) log("[ERROR SEGV  ] ", __FILE__, __LINE__, #x); \
    else if (!(x))               log("[ERROR ASSERT] ", __FILE__, __LINE__, #x); \
    else                         log("[PASS        ] ", __FILE__, __LINE__, #x); \
} while(0)

# define TEST_SEGV(x) do {                                                      \
    SANDBOX(x);                                                                 \
    if (!WIFEXITED(testSegvPid)) log("[ERROR SEGV  ] ", __FILE__, __LINE__, #x); \
    else                         log("[PASS        ] ", __FILE__, __LINE__, #x); \
} while(0)

/*
** log.cpp
*/

void log(const std::string& prefix,
         const std::string& filename,
         int lineNum,
         const std::string& code);

/*
** vector_test.cpp
*/

void vectorTest();

#endif
