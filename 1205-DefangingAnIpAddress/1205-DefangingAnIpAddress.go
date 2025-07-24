// Last updated: 7/24/2025, 8:27:51 AM
func defangIPaddr(address string) string {
    return strings.ReplaceAll(address, ".", "[.]")
}