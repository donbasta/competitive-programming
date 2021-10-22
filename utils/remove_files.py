import os

EXT = "out"
DEL_BINARY = True
EXTS = ["cpp", "py", "c", "rs"]


def remove_files(root):
    count_delete = 0
    size_delete = 0
    children = os.listdir(root)
    for child in children:
        child = os.path.join(root, child)
        if os.path.isdir(child):
            count_deleted_from_child, size_deleted_from_child = remove_files(child)
            count_delete += count_deleted_from_child
            size_delete += size_deleted_from_child
        else:
            extension = child.split(".")[-1]
            if extension == EXT:
                size_delete += os.path.getsize(child)
                os.remove(child)
                count_delete += 1
            if DEL_BINARY and extension not in EXTS:
                size_delete += os.path.getsize(child)
                os.remove(child)
                count_delete += 1

    return count_delete, size_delete


if __name__ == "__main__":
    deleted_binary_count, deleted_binary_size = remove_files("../submissions")
    print(
        "{} {} files are deleted! You save {} KB of space!".format(
            deleted_binary_count, EXT, deleted_binary_size / 1000
        )
    )
