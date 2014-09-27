<?php
class ClientStreamWrapper extends DrupalLocalStreamWrapper {
  /**
   * Implements abstract public function getDirectoryPath()
   */
  public function getDirectoryPath() {
    return variable_get('client_path', conf_path() . '/files');
  }

  function getExternalUrl() {
    $path = str_replace('\\', '/', $this->getTarget());
    $path1 = explode('/', $path);

    if ($path1[0] === 'styles') {
      array_shift($path1);
      $path = 'system/files/styles/' . implode('/', $path1);
    }
    else {
      $path = 'system/client/' . $path;
    }

    return url($path, array('absolute' => TRUE));
  }
}