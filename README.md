C Tutorials collection
======================

Building
-----

Each directory has a GNU Makefile which can be invoked via following ways:

This would build an executable:
```
make
```

This would build an executable and invoke tests:
```
make test
```

This would clean object files and executables:
```
make clean
```

This would build an executable using some reference implementation
```
make REFSRC=../reference/linked_list/impl.c
```

Writing
-------

In each directory $NAME there would be a file $NAME.c, where you supposed to put your implementation, then refer to **Building** in order to build and test your implementation.

Detail
------

Director | Description
-------- | -----------
reference/ | Reference implementation
common/ | Common utilities
linked\_list/ | Double-linked list task
