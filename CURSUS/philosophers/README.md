# Philosophers

## Overview

Philosophers is a concurrency problem simulation that models a group of philosophers sitting at a round table, following specific rules of behavior: eating, thinking, and sleeping. The challenge lies in managing shared resources (forks) to prevent deadlock and starvation while ensuring smooth execution using threads and mutexes.

## Features

Simulates the Dining Philosophers Problem.

Uses pthreads for concurrent execution.

Implements mutexes to manage shared resources (forks).

Ensures philosophers don’t starve or cause race conditions.

Outputs real-time state changes with timestamps.

Can run with customizable parameters for different scenarios.

## Installation

### Prerequisites

- GCC or Clang compiler
- Make
- POSIX Threads (pthread) library

### Build

Clone the repository and compile the program:

``` sh
make
```

This will generate the philo executable.

To clean up object files:

``` sh
make clean
```

To remove binaries and object files:

``` sh
make fclean
```

To recompile everything:

``` sh
make re
```

## Usage

Run the program with the required arguments:

``` sh
./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
```

**Arguments**

- number_of_philosophers - Total number of philosophers (and forks).

- time_to_die (ms) - Time a philosopher can go without eating before dying.

- time_to_eat (ms) - Time a philosopher spends eating.

- time_to_sleep (ms) - Time a philosopher spends sleeping.

- number_of_times_each_philosopher_must_eat (optional) - If set, simulation stops once all philosophers eat this many times.

**Program Rules**

- Each philosopher alternates between eating, thinking, and sleeping.

- To eat, a philosopher must pick up both the left and right fork.

- Only one fork is available between each pair of philosophers.

- If a philosopher doesn’t eat within time_to_die, they die, and the simulation stops.

- The program ensures that no data races occur.

**Logging Format**

The program logs philosopher actions in the following format:

*[timestamp_in_ms] X has taken a fork*
*[timestamp_in_ms] X is eating*
*[timestamp_in_ms] X is sleeping*
*[timestamp_in_ms] X is thinking*
*[timestamp_in_ms] X died*

Where:

- timestamp_in_ms is the elapsed time since the simulation started.

- X is the philosopher’s number.

(A death message must be printed within 10ms of actual death.)

External Functions Used

memset, printf, malloc, free, write, usleep, gettimeofday

pthread_create, pthread_detach, pthread_join

pthread_mutex_init, pthread_mutex_destroy, pthread_mutex_lock, pthread_mutex_unlock

### License

This project follows the 42 School project guidelines.