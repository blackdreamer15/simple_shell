#include "shell.h"

/**
 * ncmp-compares name of environment variable
 * @str: input string
 * @s: string to be compared
 * @l: size of s
 * Return: 1 on success or 0
 */
int ncmp(char *str, char const *s, size_t l)
{
	size_t i;

	for (i = 0; i < l; i++)
	{
		if (str[i] && (s[i] == str[i]))
			continue;
		return (i);
	}
	return (i);
}

/**
 * _setenv-sets path to a new to a new value
 * @name: name of variable
 *
 * @value: value of var
 * @overwrite: flag for overwriting value
 * Return: return 0 on success or -1 otherwise
 */
int _setenv(const char *name, const char *value, int overwrite)
{
	size_t i = 0, l = _strlen((char *)(name));
	char *s, *str;
	char **tmp = environ;

	if (!name)
	{
		return (-1);
	}
	str = _strcat((char *)name, "=");
	s = str;
	str = _strcat(str, (char *)value);

	while (*tmp)
	{
		i = ncmp(*tmp, name, l);
		if (((*tmp)[i] == '=') && (i == l))
		{
			if (overwrite)
			{
				*tmp = str;
				free(s);
				return (0);
			}
			return (0);
		}
		tmp++;
	}
	free(*tmp);
	*tmp = str;
	free(s);
	*(tmp + 1) = NULL;
	return (0);
}

/**
 * _getenv- gets a particular env variable
 * @name: name of variable
 *
 * Return: value of variable.
 */
char *_getenv(const char *name)
{
	char **en = environ;
	size_t i = 0, l = _strlen((char *)name);

	while (*en)
	{
		for (i = 0; i < l; i++)
		{
			if ((*en)[i] && (name[i] == (*en)[i]))
				continue;
			break;
		}
		if (((*en)[i] == '=') && (i == l))
			return (&((*en)[i + 1]));

		en++;
	}
	return (0);
}

/**
 * mklist-adds the directoy of path in list
 *
 * @s: variable name
 * Return: pointer to list
 */
list_t *mklist(char *s)
{
	char *str;

	list_t *e_list;

	e_list = malloc(sizeof(list_t));
	if (!e_list)
		return (0);
	str = strtok(_getenv(s), ":");
	while (str != NULL)
	{
		add_node(&e_list, str);
		str = strtok(NULL, ":");
	}
	return (e_list);
}

/**
 * _unsetenv- deletes member from environment variable
 * @name: varible name
 *
 * Return: 1 on success
 */
int _unsetenv(const char *name)
{
	char **sp, **en = environ;
	size_t i = 0, l = _strlen((char *)name);

	while (*en)
	{
		i = ncmp(*en, name, l);
		if ((i == l) && ((*en)[i] == '='))
		{
			free(*en);
			sp = en;
			do {
				sp[0] = sp[1];
			} while (*sp++);
			return (0);
		}
		en++;
	}
	return (1);
}
