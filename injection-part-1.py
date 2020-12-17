import subprocess

def main():
    malicious_command_injection_input = ""
    malicious_path_traversal_input = ""

    print_header("COMMAND INJECTION EXPLOITATION")
    echo_wrapper_vulnerable("Hello, world!")
    echo_wrapper_vulnerable(malicious_command_injection_input)
    
    print_header("COMMAND INJECTION MITIGATION")
    echo_wrapper_secure("Hello, world!")
    echo_wrapper_secure(malicious_command_injection_input)

    print_header("PATH TRAVERSAL EXPLOITATION")
    file_reader_vulnerable("boring_public_file")
    file_reader_vulnerable(malicious_path_traversal_input)
    
    print_header("PATH TRAVERSAL MITIGATION")
    file_reader_secure("boring_public_file")
    file_reader_secure(malicious_path_traversal_input)

def echo_wrapper_vulnerable(text):
    subprocess.run("echo \"" + text + "\";", shell=True)

def echo_wrapper_secure(text):
    # TODO validate the input
    echo_wrapper_vulnerable(text)

def file_reader_vulnerable(filepath):
    with open("./public_files/" + filepath + ".txt") as file:
        file_contents = file.read()
        print(file_contents)

def file_reader_secure(filepath):
    # TODO validate the input
    file_reader_vulnerable(filepath)

def print_header(header):
    print(f"\n{'*' * 12} {header}:")

main()
