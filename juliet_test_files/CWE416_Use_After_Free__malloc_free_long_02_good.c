/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE416_Use_After_Free__malloc_free_long_02.c
Label Definition File: CWE416_Use_After_Free__malloc_free.label.xml
Template File: sources-sinks-02.tmpl.c
*/
/*
 * @description
 * CWE: 416 Use After Free
 * BadSource:  Allocate data using malloc(), initialize memory block, and Deallocate data using free()
 * GoodSource: Allocate data using malloc() and initialize memory block
 * Sinks:
 *    GoodSink: Do nothing
 *    BadSink : Use data
 * Flow Variant: 02 Control flow: if(1) and if(0)
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#ifndef OMITGOOD

/* goodB2G1() - use badsource and goodsink by changing the second 1 to 0 */
static void goodB2G1()
{
    long * data;
    /* Initialize data */
    data = NULL;
    if(1)
    {
        data = (long *)malloc(100*sizeof(long));
        {
            size_t i;
            for(i = 0; i < 100; i++)
            {
                data[i] = 5L;
            }
        }
        /* POTENTIAL FLAW: Free data in the source - the bad sink attempts to use data */
        free(data);
    }
    if(0)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
    }
    else
    {
        /* FIX: Don't use data that may have been freed already */
        /* POTENTIAL INCIDENTAL - Possible memory leak here if data was not freed */
        /* do nothing */
        ; /* empty statement needed for some flow variants */
    }
}

/* goodB2G2() - use badsource and goodsink by reversing the blocks in the second if */
static void goodB2G2()
{
    long * data;
    /* Initialize data */
    data = NULL;
    if(1)
    {
        data = (long *)malloc(100*sizeof(long));
        {
            size_t i;
            for(i = 0; i < 100; i++)
            {
                data[i] = 5L;
            }
        }
        /* POTENTIAL FLAW: Free data in the source - the bad sink attempts to use data */
        free(data);
    }
    if(1)
    {
        /* FIX: Don't use data that may have been freed already */
        /* POTENTIAL INCIDENTAL - Possible memory leak here if data was not freed */
        /* do nothing */
        ; /* empty statement needed for some flow variants */
    }
}

/* goodG2B1() - use goodsource and badsink by changing the first 1 to 0 */
static void goodG2B1()
{
    long * data;
    /* Initialize data */
    data = NULL;
    if(0)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
    }
    else
    {
        data = (long *)malloc(100*sizeof(long));
        {
            size_t i;
            for(i = 0; i < 100; i++)
            {
                data[i] = 5L;
            }
        }
        /* FIX: Do not free data in the source */
    }
    if(1)
    {
        /* POTENTIAL FLAW: Use of data that may have been freed */
        printLongLine(data[0]);
        /* POTENTIAL INCIDENTAL - Possible memory leak here if data was not freed */
    }
}

/* goodG2B2() - use goodsource and badsink by reversing the blocks in the first if */
static void goodG2B2()
{
    long * data;
    /* Initialize data */
    data = NULL;
    if(1)
    {
        data = (long *)malloc(100*sizeof(long));
        {
            size_t i;
            for(i = 0; i < 100; i++)
            {
                data[i] = 5L;
            }
        }
        /* FIX: Do not free data in the source */
    }
    if(1)
    {
        /* POTENTIAL FLAW: Use of data that may have been freed */
        printLongLine(data[0]);
        /* POTENTIAL INCIDENTAL - Possible memory leak here if data was not freed */
    }
}

void CWE416_Use_After_Free__malloc_free_long_02_good()
{
    goodB2G1();
    goodB2G2();
    goodG2B1();
    goodG2B2();
}

#endif /* OMITGOOD */

/* Below is the main(). It is only used when building this testcase on
   its own for testing or for building a binary to use in testing binary
   analysis tools. It is not used when compiling all the testcases as one
   application, which is how source code analysis tools are tested. */

#ifdef INCLUDEMAIN

int main(int argc, char * argv[])
{
    /* seed randomness */
    srand( (unsigned)time(NULL) );
#ifndef OMITGOOD
    printLine("Calling good()...");
    CWE416_Use_After_Free__malloc_free_long_02_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
    return 0;
}

#endif
