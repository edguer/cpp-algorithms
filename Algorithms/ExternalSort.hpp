#include <bits/stdc++.h>
#include <string>
#include <cctype>
#include "Sorting.hpp"

#ifndef EXTERNALSORTING
#define EXTERNALSORTING

using namespace std;

namespace Contoso
{
    namespace ExternalSorting
    {
        namespace
        {
            FILE *OpenFile(char *file_path, char *access_mode)
            {
                FILE *file = fopen(file_path, access_mode);
                if (file == NULL)
                {
                    string file_path_str = file_path;
                    string error_message = "Error while opening file " + file_path_str;

                    perror(error_message.c_str());
                    exit(EXIT_FAILURE);
                }

                return file;
            }
            int SplitAndSort(char *input_file_path, int partitions, int partition_size)
            {
                int total_size = 0;
                FILE *input_file = OpenFile(input_file_path, "r");

                // create output files
                FILE *output_files[partitions];
                char file_name[2];
                for (int partition = 0; partition < partitions; partition++)
                {
                    snprintf(file_name, sizeof(file_name), "%d", partition);
                    output_files[partition] = OpenFile(file_name, "w");
                }

                // allocate array
                int *arr = (int *)malloc(partition_size * sizeof(int));

                // start reading chunks, ordering and writing to the output files
                for (int partition = 0; partition < partitions; partition++)
                {
                    int i = 0;
                    // reads input file until the number of partition size
                    for (; i < partition_size; i++)
                    {
                        if (fscanf(input_file, "%d ", &arr[i]) != 1)
                        {
                            // leaves if there is nothing else to read
                            break;
                        }
                    }

                    // sorting
                    Contoso::Sorting::MergeSort(arr, i - 1);

                    // write to files
                    for (int j = 0; j < i; j++)
                    {
                        fprintf(output_files[partition], "%d ", arr[j]);
                        total_size++;
                    }
                }

                // close output files
                for (int partition = 0; partition < partitions; partition++)
                {
                    fclose(output_files[partition]);
                }

                return total_size;
            }
            void MergeAndSort(char *output_file_path, int partitions, int partition_size, int total_size)
            {
                // open output files
                FILE *output_files[partitions];
                char file_name[2];
                for (int partition = 0; partition < partitions; partition++)
                {
                    snprintf(file_name, sizeof(file_name), "%d", partition);
                    output_files[partition] = OpenFile(file_name, "r");
                }

                FILE *output_file = OpenFile(output_file_path, "w");

                bool finished = false;
                bool stop_partition[partitions];
                bool finished_partition[partitions];
                int elements[partitions];
                int lower_value = INT32_MAX;
                int lower_value_partition = INT32_MIN;
                for (int i = 0; i < partitions; i++)
                {
                    stop_partition[i] = false;
                    finished_partition[i] = false;
                    elements[i] = 0;
                }

                while (!finished)
                {
                    for (int i = 0; i < partitions; i++)
                    {
                        if (finished_partition[i])
                        {
                            continue;
                        }

                        if (!stop_partition[i] && fscanf(output_files[i], "%d ", &elements[i]) != 1)
                        {
                            finished_partition[i] = true;
                        }
                        else
                        {
                            stop_partition[i] = true;
                        }

                        if (elements[i] < lower_value)
                        {
                            lower_value = elements[i];
                            lower_value_partition = i;
                        }
                    }

                    finished = true;
                    for (int i = 0; i < partitions; i++)
                    {
                        if (!finished_partition[i])
                        {
                            finished = false;
                        }
                    }

                    if (finished)
                    {
                        break;
                    }

                    fprintf(output_file, "%d ", lower_value);
                    stop_partition[lower_value_partition] = false;
                    lower_value = INT32_MAX;
                }

                for (int partition = 0; partition < partitions; partition++)
                {
                    fclose(output_files[partition]);
                }
                fclose(output_file);
            }
        } // namespace
        void Sort(char *input_file_path, char *output_file_path, int partitions, int partition_size)
        {
            int total_size = SplitAndSort(input_file_path, partitions, partition_size);
            MergeAndSort(output_file_path, partitions, partition_size, total_size);
        }
    } // namespace ExternalSorting
} // namespace Contoso

#endif